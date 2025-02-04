
#include "api.hpp" // IWYU pragma: keep
#include "constants.hpp"
#include "intake.hpp"
#include <atomic>
#include "pros/misc.h"
#include "robodash.hpp"
#include "subsystems.hpp"

/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

bool changed = false;

/*
pros::Task intake_task([]() {
  while(true)
  {
    if(true)
    {
      double new_hook_speed = StratusQuo::hook_motor_speed.load();
      double new_roller_speed = StratusQuo::roller_motor_speed.load();
      StratusQuo::intake.get_hook_motor().move(StratusQuo::hook_motor_speed);
      StratusQuo::intake.get_roller_motor().move(StratusQuo::roller_motor_speed);
      if(StratusQuo::roller_motor_speed == StratusQuo::hook_motor_speed == 0) StratusQuo::intake.brake();
      else if(StratusQuo::roller_motor_speed == 0) StratusQuo::intake.get_roller_motor().brake();
      else if(StratusQuo::hook_motor_speed == 0) StratusQuo::intake.get_hook_motor().brake();
      pros::delay(10);
    }
    else
    {
      pros::delay(300);
      StratusQuo::intake.get_hook_motor().move(-127);
      pros::delay(200);
      StratusQuo::intake.get_hook_motor().move(0);
      pros::delay(10);
      StratusQuo::bad_color.store(!StratusQuo::bad_color.load());
    }
    StratusQuo::intake.set_piston(StratusQuo::is_intake_up.load());
  }
}); */

pros::Task limit_switch_task([]() {
  while (true) {
    if (StratusQuo::limit_switch.get_new_press() && StratusQuo::isAutoClampEnabled) {
      master.rumble("-");
      StratusQuo::set_clamp = true;
      changed = true;
    }
    StratusQuo::clamp.set(StratusQuo::set_clamp);
    if(changed) pros::delay(1000);
    changed = false;
    pros::delay(75);
  }
});

void initialize() {
  using namespace StratusQuo;

  pros::delay(500);

  chassis.opcontrol_curve_buttons_toggle(true);   // Enables modifying the controller curve with buttons on the joysticks
  chassis.opcontrol_drive_activebrake_set(0.0);   // Sets the active brake kP. We recommend ~2.  0 will disable.
  chassis.opcontrol_curve_default_set(0.0, 0.0);  // Defaults for curve. If using tank, only the first parameter is used. (Comment this line out if you have an SD card!)

  StratusQuo::default_constants();

  chassis.drive_imu_calibrate(false);
  chassis.drive_sensor_reset();

  color_selector.run_auton();

  master.rumble(chassis.drive_imu_calibrated() ? "." : "---");
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
  // . . .
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
  // . . .
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
  using namespace StratusQuo;
  chassis.pid_targets_reset();   // Resets PID targets to 0
  chassis.drive_imu_reset();     // Reset gyro position to 0
  chassis.drive_sensor_reset();  // Reset drive sensors to 0
  // chassis.odom_xyt_set(0_in, 0_in, 0_deg);    // Set the current position, you can start at a specific position with this
  chassis.drive_brake_set(pros::E_MOTOR_BRAKE_HOLD);  // Set motors to hold.  This helps autonomous consistency

  //.resume();

  /*
  Odometry and Pure Pursuit are not magic

  It is possible to get perfectly consistent results without tracking wheels,
  but it is also possible to have extremely inconsistent results without tracking wheels.
  When you don't use tracking wheels, you need to:
   - avoid wheel slip
   - avoid wheelies
   - avoid throwing momentum around (super harsh turns, like in the example below)
  You can do cool curved motions, but you have to give your robot the best chance
  to be consistent
  */

  //*
  // Uncomment this to use the auton selector
  if(selector.get_auton())
  {
    selector.run_auton();
  }
  else
  {
    chassis.pid_drive_set(-6_in, 110);
    chassis.pid_wait();
  }// */
  // Uncomment to edit a specific auton.
  //six_ring_red();
}

/**
 * Simplifies printing tracker values to the brain screen
 */
/*
void screen_print_tracker(ez::tracking_wheel *tracker, std::string name, int line) {
 std::string tracker_value = "", tracker_width = "";
 // Check if the tracker exists
 if (tracker != nullptr) {
   tracker_value = name + " tracker: " + util::to_string_with_precision(tracker->get());             // Make text for the tracker value
   tracker_width = "  width: " + util::to_string_with_precision(tracker->distance_to_center_get());  // Make text for the distance to center
 }
 ez::screen_print(tracker_value + tracker_width, line);  // Print final tracker text
} */

/**
 * Ez screen task
 * Adding new pages here will let you view them during user control or autonomous
 * and will help you debug problems you're having
 */
/*void ez_screen_task() {
 using namespace StratusQuo;
 while (true) {
   // Only run this when not connected to a competition switch
   if (!pros::competition::is_connected()) {
     // Blank page for odom debugging
     if (chassis.odom_enabled() && !chassis.pid_tuner_enabled()) {
       // If we're on the first blank page...
       if (ez::as::page_blank_is_on(0)) {
         // Display X, Y, and Theta
         ez::screen_print("x: " + util::to_string_with_precision(chassis.odom_x_get()) +
                              "\ny: " + util::to_string_with_precision(chassis.odom_y_get()) +
                              "\na: " + util::to_string_with_precision(chassis.odom_theta_get()),
                          1);  // Don't override the top Page line

         // Display all trackers that are being used
         screen_print_tracker(chassis.odom_tracker_left, "l", 4);
         screen_print_tracker(chassis.odom_tracker_right, "r", 5);
         screen_print_tracker(chassis.odom_tracker_back, "b", 6);
         screen_print_tracker(chassis.odom_tracker_front, "f", 7);
       }
     }
   }

   // Remove all blank pages when connected to a comp switch
   else {
     if (ez::as::page_blank_amount() > 0)
       ez::as::page_blank_remove_all();
   }

   pros::delay(ez::util::DELAY_TIME);
 }
}
pros::Task ezScreenTask(ez_screen_task); */

/**
 * Gives you some extras to run in your opcontrol:
 * - run your autonomous routine in opcontrol by pressing DOWN and B
 *   - to prevent this from accidentally happening at a competition, this
 *     is only enabled when you're not connected to competition control.
 * - gives you a GUI to change your PID values live by pressing X
 */
void ez_template_extras() {
  using namespace StratusQuo;
  // Only run this when not connected to a competition switch
  if (!pros::competition::is_connected()) {
    // PID Tuner
    // - after you find values that you're happy with, you'll have to set them in auton.cpp

    // Enable / Disable PID Tuner
    //  When enabled:
    //  * use A and Y to increment / decrement the constants
    //  * use the arrow keys to navigate the constants
    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X))
      chassis.pid_tuner_toggle();

    // Trigger the selected autonomous routine
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B) && master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
      pros::motor_brake_mode_e_t preference = chassis.drive_brake_get();
      autonomous();
      chassis.drive_brake_set(preference);
    }

    // Allow PID Tuner to iterate
    chassis.pid_tuner_iterate();
  }

  // Disable PID Tuner when connected to a comp switch
  else {
    if (chassis.pid_tuner_enabled())
      chassis.pid_tuner_disable();
  }
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
  // This is preference to what you like to drive on
  pros::motor_brake_mode_e_t driver_preference_brake = pros::E_MOTOR_BRAKE_COAST;

  StratusQuo::chassis.drive_brake_set(driver_preference_brake);

  bool left_doinker_down = false;
  bool pto_enabled = false;

  //sorting_task.suspend();
  while (true) {
    // PID Tuner
    // After you find values that you're happy with, you'll have to set them in auton.cpp
    /*
    if (!pros::competition::is_connected()) {
      // Enable / Disable PID Tuner
      //  When enabled:
      //  * use A and Y to increment / decrement the constants
      //  * use the arrow keys to navigate the constants
      if (master.get_digital_new_press(DIGITAL_X))
        StratusQuo::chassis.pid_tuner_toggle();

      // Trigger the selected autonomous routine
      if (master.get_digital(DIGITAL_B) && master.get_digital(DIGITAL_DOWN)) {
        autonomous();
        StratusQuo::chassis.drive_brake_set(driver_preference_brake);
      }

      StratusQuo::chassis.pid_tuner_iterate();  // Allow PID Tuner to iterate
    }
    */
    StratusQuo::chassis.opcontrol_tank();  // Tank control
    StratusQuo::chassis.pto_toggle({StratusQuo::chassis.left_motors[2], StratusQuo::chassis.right_motors[2]}, pto_enabled);

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_UP) && master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
      StratusQuo::isColorSortEnabled = !StratusQuo::isColorSortEnabled;
      continue;
    }
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN) && master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
      StratusQuo::isAutoClampEnabled = !StratusQuo::isAutoClampEnabled;
      continue;
    }

    // . . .
    // Put more user control code here!
    // . . .

    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
      pto_enabled = !pto_enabled;
      StratusQuo::lady_brown.set_pto(pto_enabled);
    }
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
      pto_enabled = true;
      StratusQuo::lady_brown.set_pto(pto_enabled);
    }

    if (pto_enabled) {
      if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
        StratusQuo::lady_brown.move(-127);
      } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
        StratusQuo::lady_brown.move(127);
      else
        StratusQuo::lady_brown.brake();
    } else {
      // Drivetrain working as it should I think?
    }

    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
    {
      /*
      hook_speed = 127;
      roller_speed = 127; */
      //StratusQuo::intake_speed_set(127, 127);
      StratusQuo::intake.move(127);
    }
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
    {
      /* hook_speed = -127;
      roller_speed = -127; */
      //StratusQuo::intake_speed_set(-127, -127);
      StratusQuo::intake.move(-127);
    }
    else
    {
      /* roller_speed = 0;
      hook_speed = 0; */
      //StratusQuo::intake_speed_set(0, 0);
      StratusQuo::intake.brake();
    }

    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
      StratusQuo::lady_brown.toggle();
      if (pto_enabled) {
        pto_enabled = !pto_enabled;
        StratusQuo::lady_brown.set_pto(pto_enabled);
      }
    }

    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
      StratusQuo::left_doinker.set(!left_doinker_down);
      left_doinker_down = !left_doinker_down;
    }

    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) {
      StratusQuo::right_doinker.set(!StratusQuo::right_doinker.get());
    }

    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)) {
      StratusQuo::intake.toggle();
    }

    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) StratusQuo::set_clamp = !StratusQuo::set_clamp;

    pros::delay(ez::util::DELAY_TIME);  // This is used for timer calculations!  Keep this ez::util::DELAY_TIME
  }
}
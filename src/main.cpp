#include "main.h"

#include "autons.hpp"
#include "pros/misc.h"
#include "subsystems.hpp"

bool pto_enabled = false;
bool limit_switch_pressed = false;

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
void initialize() {
  // Print our branding over your terminal :D
  ez::ez_template_print();

  pros::delay(500);  // Stop the user from doing anything while legacy ports configure

  // Configure your StratusQuo::chassis controls
  StratusQuo::chassis.opcontrol_curve_buttons_toggle(true);  // Enables modifying the controller curve with buttons on the joysticks
  StratusQuo::chassis.opcontrol_drive_activebrake_set(0);    // Sets the active brake kP. We recommend ~2.  0 will disable.
  StratusQuo::chassis.opcontrol_curve_default_set(0, 0);     // Defaults for curve. If using tank, only the first parameter is used. (Comment this line out if you have an SD card!)

  // Set the drive to your own constants from autons.cpp!
  default_constants();

  // These are already defaulted to these buttons, but you can change the left/right curve buttons here!
  // StratusQuo::chassis.opcontrol_curve_buttons_left_set(pros::E_CONTROLLER_DIGITAL_LEFT, pros::E_CONTROLLER_DIGITAL_RIGHT);  // If using tank, only the left side is used.
  // StratusQuo::chassis.opcontrol_curve_buttons_right_set(pros::E_CONTROLLER_DIGITAL_Y, pros::E_CONTROLLER_DIGITAL_A);
  
  // Autonomous Selector using LLEMU
  ez::as::auton_selector.autons_add({
      Auton("Red four ring", red_side_four_ring),
      Auton("Blue four ring", blue_side_four_ring),
      Auton("Blue goal rush", blue_side_goal_rush),
      Auton("Example Drive\n\nDrive forward and come back.", drive_example),
      Auton("Example Turn\n\nTurn 3 times.", turn_example),
      Auton("Drive and Turn\n\nDrive forward, turn, come back. ", drive_and_turn),
      Auton("Drive and Turn\n\nSlow down during drive.", wait_until_change_speed),
      Auton("Swing Example\n\nSwing in an 'S' curve", swing_example),
      Auton("Motion Chaining\n\nDrive forward, turn, and come back, but blend everything together :D", motion_chaining),
      Auton("Combine all 3 movements", combining_movements),
      Auton("Interference\n\nAfter driving forward, robot performs differently if interfered or not.", interfered_example),
  });
  
  // Initialize StratusQuo::chassis and auton selector
  StratusQuo::chassis.initialize();
  ez::as::initialize();
  master.rumble(".");
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
  StratusQuo::chassis.pid_targets_reset();                // Resets PID targets to 0
  StratusQuo::chassis.drive_imu_reset();                  // Reset gyro position to 0
  StratusQuo::chassis.drive_sensor_reset();               // Reset drive sensors to 0
  StratusQuo::chassis.drive_brake_set(MOTOR_BRAKE_HOLD);  // Set motors to hold.  This helps autonomous consistency

  ez::as::auton_selector.selected_auton_call();  // Calls selected auton from autonomous selector
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
  pros::motor_brake_mode_e_t driver_preference_brake = MOTOR_BRAKE_COAST;

  StratusQuo::chassis.drive_brake_set(driver_preference_brake);

  bool doinker_down = false;

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

    limit_switch_pressed = StratusQuo::left_limit_switch.get_new_press()/* && StratusQuo::right_limit_switch.get_value()*/;

    // . . .
    // Put more user control code here!
    // . . .

    if(pto_enabled)
    {
      if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
      {
        StratusQuo::lady_brown.move(-127);
      }
      else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
        StratusQuo::lady_brown.move(127);
      else
        StratusQuo::lady_brown.brake();
    }
    else
    {
      // Drivetrain working as it should I think?
    }

    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN))
    {
      StratusQuo::lady_brown.set_pto(pto_enabled);
      pto_enabled = !pto_enabled;
    }

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
    {
      StratusQuo::intake.move(127);
    }
    else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2))
    {
      StratusQuo::intake.move(-127);
    }
    else StratusQuo::intake.brake();

    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y))
    {
      StratusQuo::lady_brown.toggle();
    }
    if(limit_switch_pressed)
    {
      StratusQuo::clamp.set(true);
    }

    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A))
    {
      StratusQuo::doinker.set(!doinker_down);
      doinker_down = !doinker_down;
    }

    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) StratusQuo::clamp.toggle();

    pros::delay(ez::util::DELAY_TIME);  // This is used for timer calculations!  Keep this ez::util::DELAY_TIME
  }
}
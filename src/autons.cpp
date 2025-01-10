// Intent - Autonomous functions

#include "autons.hpp"
#include "intake.hpp"
#include "main.h" // IWYU pragma: keep
#include "subsystems.hpp"

/////
// For installation, upgrading, documentations, and tutorials, check out our website!
// https://ez-robotics.github.io/EZ-Template/
/////

void testing_pid_auto()
{
  using namespace StratusQuo;
  chassis.drive_angle_set(0_deg);
  chassis.pid_drive_set(48_in, 110);
  chassis.pid_wait();
}

#pragma region Goal Rushes
void blue_side_goal_rush()
{
  using namespace StratusQuo;
  chassis.pid_drive_set(46_in, 127);
  intake.move(127);
  chassis.pid_wait_quick_chain();
  intake.brake();
  intake.move_bottom_motor(127);
  doinker.set(true);
  pros::delay(250);
  chassis.pid_turn_set(100_deg, 127);
  chassis.pid_wait_quick();
  doinker.set(false);
  pros::delay(450);
  chassis.pid_turn_set(-60_deg, 110);
  chassis.pid_wait();
  chassis.pid_drive_set(-16_in, 110);
  chassis.pid_wait();
  set_clamp = true;
  intake.move(-127);
  intake.move_bottom_motor(127);
  chassis.pid_turn_set(90_deg, 70);
  chassis.pid_wait_until(0_deg);
  intake.move(127);
  chassis.pid_wait();
  pros::delay(500);
  set_clamp = false;
  chassis.pid_turn_set(-68_deg, 110);
  chassis.pid_wait();
  chassis.pid_drive_set(-15_in, 110);
  chassis.pid_wait();
  set_clamp = true;
  intake.move(-127);
  intake.move_bottom_motor(127);
  chassis.pid_turn_set(-225_deg, 110);
  chassis.pid_wait();
  chassis.pid_drive_set(36_in, 110);
  intake.move(127);
  intake.toggle();
  chassis.pid_wait();
  intake.toggle();
  chassis.pid_drive_set(-12_in, 40);
  chassis.pid_wait();
  chassis.pid_turn_set(-118_deg, 110);
  chassis.pid_wait();
  chassis.pid_drive_set(68_in, 110);
  chassis.pid_wait();
  chassis.pid_drive_set(-12_in, 40);
  chassis.pid_wait();
}


void red_side_goal_rush()
{
  // TODO: Lower speed, then try to optimize with speed.
  using namespace StratusQuo;
  chassis.drive_angle_set(180_deg);
  chassis.pid_drive_set(-28_in, 127);
  chassis.pid_wait_quick();
  chassis.pid_turn_set(150_deg, 127);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(-18_in, 127);
  chassis.pid_wait_quick();
  pros::delay(25);
  set_clamp = true;
  intake.move(-127);
  pros::delay(100);
  chassis.pid_drive_set(8_in, 127);
  intake.move(127);
  chassis.pid_wait();
  chassis.pid_turn_set(225_deg, 127);
  chassis.pid_wait();
  chassis.pid_drive_set(16_in, 60);
  chassis.pid_wait_until(12_in);
  intake.brake();
  chassis.pid_wait();
  pros::delay(100);
  set_clamp = false;
  chassis.pid_turn_set(90_deg, 60);
  chassis.pid_wait();
  chassis.pid_drive_set(-20_in, 60);
  chassis.pid_wait();
  set_clamp = true;
  intake.move(-127);
  pros::delay(25);
  intake.move(127);
  chassis.pid_turn_set(225_deg, 60);
  chassis.pid_wait();
  intake.toggle();
  chassis.pid_drive_set(38_in, 40);
  chassis.pid_wait();
  intake.toggle();
  chassis.pid_turn_set(0_deg, 30);
  chassis.pid_wait_quick();
  chassis.pid_drive_set(24_in, 60);
}

void red_side_fast_goal_rush()
{
  using namespace StratusQuo;
  chassis.drive_angle_set(45_deg);
  chassis.pid_drive_set(38_in, 127);
  chassis.pid_wait();
  doinker.set(true);
  pros::delay(500);
  chassis.pid_turn_set(100_deg, 110, true);
  chassis.pid_wait();
  doinker.set(false);
  chassis.pid_drive_set(-12_in, 127);
  chassis.pid_wait();
  set_clamp = true;
  pros::delay(100);
  chassis.pid_wait();
  intake.move(127);
  pros::delay(800);
  chassis.pid_wait();
  set_clamp = false;
  chassis.pid_wait();
  chassis.pid_turn_set(140_deg, 110, true);
  chassis.pid_wait();
  chassis.pid_drive_set(31_in, 127);
  intake.move_bottom_motor(127);
  chassis.pid_wait();
  chassis.pid_drive_set(-4_in, 127);
  chassis.pid_wait();
  chassis.pid_turn_set(220_deg, 110, true);
  chassis.pid_wait();
  chassis.pid_drive_set(-12_in, 127);
  chassis.pid_wait();
  set_clamp = true;
  intake.move( 127);
  chassis.pid_wait();
  chassis.pid_turn_set(272_deg, 110, true);
  chassis.pid_wait();
  chassis.pid_drive_set(40_in, 127);
  chassis.pid_wait_quick_chain();
  intake.toggle();
  intake.brake();
  intake.move(127);
  chassis.pid_wait();
  chassis.pid_drive_set(18_in, 50); 
  chassis.pid_wait();
  intake.toggle();
  chassis.pid_wait();
  chassis.pid_turn_set(390_deg, 60);
  chassis.pid_wait();
  chassis.pid_drive_set(32_in, 110, true);
}
#pragma endregion

#pragma region Ring Rushes
void blue_side_ring_rush()
{
  using namespace StratusQuo;
  chassis.drive_angle_set(0_deg);
  ring_rush_mech.set(true);
  chassis.pid_drive_set(47_in, 127);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(-24_in, 110);
  chassis.pid_wait_quick();
  ring_rush_mech.set(false);
  pros::delay(250);
  chassis.pid_turn_set(90_deg, 110);
  chassis.pid_wait_quick();
  chassis.pid_drive_set(-22_in, 110);
  chassis.pid_wait_quick();
  intake.move(-127);
  set_clamp = true;
  chassis.pid_turn_set(52.5_deg, 110);
  chassis.pid_wait_quick();
  intake.brake();
  chassis.pid_drive_set(44_in, 60);
  intake.move(127);
  chassis.pid_wait();
  chassis.pid_drive_set(-24_in, 110);
  chassis.pid_wait();
  intake.brake();
  chassis.pid_turn_set(190_deg, 110);
  chassis.pid_wait();
  chassis.pid_drive_set(44_in, 110);
  intake.move(127);
  chassis.pid_wait();
  chassis.pid_turn_set(275_deg, 110);
  chassis.pid_wait();
  intake.toggle();
  chassis.pid_drive_set(11_in, 90);
  chassis.pid_wait();
  intake.toggle();
  pros::delay(400);
  chassis.pid_drive_set(-11_in, 40);
  chassis.pid_wait();
  chassis.pid_drive_set(8.5_in, 90);
  chassis.pid_wait();
  chassis.pid_turn_set(340_deg, 110);
  chassis.pid_wait();
  chassis.pid_drive_set(28_in, 110);
}


void red_side_ring_rush()
{
  using namespace StratusQuo;
  ring_rush_mech.set(true);
  chassis.pid_drive_set(46_in, 127);
  chassis.pid_wait();
  chassis.pid_drive_set(-15_in, 110);
  chassis.pid_wait();
  chassis.pid_turn_set(20_deg, 110);
  chassis.pid_wait();
  ring_rush_mech.set(false);
  pros::delay(100);
  chassis.pid_drive_set(-8_in, 110);
  chassis.pid_wait();
  chassis.pid_turn_set(-95_deg, 110);
  chassis.pid_wait();
  chassis.pid_drive_set(-18_in, 110);
  chassis.pid_wait();
  pros::delay(25);
  set_clamp = true;
  intake.move(-127);
  chassis.pid_turn_set(-20_deg, 110);
  chassis.pid_wait();
  intake.move(127);
  chassis.pid_drive_set(12_in, 110);
  chassis.pid_wait();
  chassis.pid_turn_set(-70_deg, 110);
  chassis.pid_wait_quick_chain();
  chassis.pid_drive_set(28_in, 90);
  chassis.pid_wait();
  chassis.pid_drive_set(-8_in, 110);
  chassis.pid_wait();
  chassis.pid_turn_set(-200_deg, 110);
  chassis.pid_wait();
  chassis.pid_drive_set(48_in, 110);
  chassis.pid_wait();
  chassis.pid_turn_set(-300_deg, 110);
  chassis.pid_wait();
  chassis.pid_drive_set(26_in, 110);
}
#pragma endregion

#pragma region AWPs
void solo_awp()
{
  using namespace StratusQuo;
  lady_brown.set_pto(false);
  pros::delay(100);
  lady_brown.move(-127);
  pros::delay(325);
  lady_brown.move(127);
  pros::delay(325);
  lady_brown.set_pto(true);

  chassis.pid_drive_set(-24_in, 127);
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_set(45_deg, 127);
  chassis.pid_wait();
  chassis.pid_drive_set(-22_in, 110);
  chassis.pid_wait_quick_chain();
  intake.move(-127);
  intake.move_bottom_motor(127);
  pros::delay(100);
  set_clamp = true;
  chassis.pid_turn_set(110_deg, 127);
  chassis.pid_wait_until(65_deg);
  intake.brake();
  chassis.pid_wait();
  intake.move(127);
  chassis.pid_drive_set(24_in, 127);
  chassis.pid_wait();
  chassis.pid_turn_set(-27_deg, 127);
  chassis.pid_wait();
  chassis.pid_drive_set(48.5_in, 110);
  intake.toggle();
  chassis.pid_wait_quick();
  intake.toggle();
  intake.brake();
  intake.move_bottom_motor(127);
  set_clamp = false;
  chassis.pid_turn_set(87.5_deg, 60);
  chassis.pid_wait();
  chassis.pid_drive_set(-40_in, 127);
  chassis.pid_wait();
  intake.move(-127);
  intake.move_bottom_motor(127);
  set_clamp = true;
  chassis.pid_turn_set(-50_deg, 127);
  intake.move(127);
  chassis.pid_wait();
  chassis.pid_drive_set(17_in, 127);
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_set(-40_deg, 127);
  chassis.pid_wait_quick();
  intake.brake();
  chassis.pid_drive_set(-40_in, 127);
  lady_brown.toggle();
}

void half_awp()
{
  using namespace StratusQuo;
  pros::delay(3000);
  lady_brown.set_pto(false);
  pros::delay(100);
  lady_brown.move(-127);
  pros::delay(325);
  lady_brown.move(127);
  pros::delay(325);
  lady_brown.set_pto(true);

  chassis.pid_drive_set(-24_in, 127);
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_set(45_deg, 127);
  chassis.pid_wait();
  chassis.pid_drive_set(-22_in, 110);
  chassis.pid_wait_quick_chain();
  intake.move(-127);
  intake.move_bottom_motor(127);
  pros::delay(100);
  set_clamp = true;
  chassis.pid_turn_set(110_deg, 127);
  chassis.pid_wait();
  intake.move(127);
  chassis.pid_drive_set(24_in, 127);
  chassis.pid_wait();
  chassis.pid_turn_set(-27_deg, 127);
  chassis.pid_wait();
  chassis.pid_drive_set(48.5_in, 110);
  intake.toggle();
  chassis.pid_wait_quick();
  intake.toggle();
  chassis.pid_turn_set(-135_deg, 40);
  chassis.pid_wait();
  chassis.pid_drive_set(24_in, 110);
}

void awp_no_ring()
{
  using namespace StratusQuo;
  lady_brown.set_pto(false);
  pros::delay(100);
  lady_brown.move(-127);
  pros::delay(325);
  lady_brown.move(127);
  pros::delay(325);
  lady_brown.set_pto(true);

  chassis.pid_drive_set(-24_in, 127);
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_set(45_deg, 127);
  chassis.pid_wait();
  chassis.pid_drive_set(-22_in, 110);
  chassis.pid_wait_quick_chain();
  intake.move(-127);
  intake.move_bottom_motor(127);
  pros::delay(100);
  set_clamp = true;
  chassis.pid_turn_set(110_deg, 127);
  chassis.pid_wait_until(65_deg);
  intake.brake();
  chassis.pid_wait();
  intake.move(127);
  chassis.pid_drive_set(24_in, 127);
  chassis.pid_wait();
  chassis.pid_turn_set(290_deg, 40);
  chassis.pid_wait();
  chassis.pid_drive_set(24_in, 110);
  lady_brown.toggle();
}

void right_side_half_awp()
{
  using namespace StratusQuo;
  lady_brown.set_pto(false);
  pros::delay(100);
  lady_brown.move(-127);
  pros::delay(325);
  lady_brown.move(127);
  pros::delay(325);
  lady_brown.set_pto(true);

  chassis.pid_drive_set(-24_in, 127);
  chassis.pid_wait_quick_chain();
  chassis.pid_turn_set(-45_deg, 127);
  chassis.pid_wait();
  chassis.pid_drive_set(-22_in, 110);
  chassis.pid_wait();
  intake.move(-127);
  intake.move_bottom_motor(127);
  pros::delay(100);
  set_clamp = true;
  chassis.pid_turn_set(-110_deg, 127);
  chassis.pid_wait_until(-65_deg);
  intake.brake();
  intake.move(127);
  chassis.pid_drive_set(24_in, 127);
  chassis.pid_wait();
  chassis.pid_turn_set(-290_deg, 127);
  chassis.pid_wait();
  chassis.pid_drive_set(48.5_in, 110);
  intake.toggle();
  chassis.pid_wait();
  intake.toggle();
  pros::delay(200);
  chassis.pid_turn_set(-340_deg, 110);
  chassis.pid_wait();
  chassis.pid_drive_set(24_in, 110);
}
#pragma endregion

#pragma region Skills
void first_autonomous_skills()
{
 using namespace StratusQuo;
chassis.drive_angle_set(180_deg);
chassis.pid_drive_set(-24_in, 60, true);
chassis.pid_wait();
set_clamp = true;
pros::delay(100); 
intake.move(127);
chassis.pid_drive_set(24_in, 60, true);
chassis.pid_wait();
intake.move(127);
chassis.pid_turn_set(270_deg, 110, true);
chassis.pid_wait();
intake.move(127);
chassis.pid_drive_set(24_in, 60, true);
chassis.pid_wait();
intake.move(127);
chassis.pid_turn_set(360_deg, 110, true);
chassis.pid_wait();
intake.move(127);
chassis.pid_drive_set(48_in, 60, true);
}

void second_autonomous_skills()
{
  using namespace StratusQuo;
  chassis.drive_angle_set(0_deg);
  intake.move(127);
  pros::delay(1000);
  intake.brake();
  chassis.pid_drive_set(24_in, 60, true);
  chassis.pid_wait();
  chassis.pid_turn_set(90_deg, 110);
  chassis.pid_wait();
  chassis.pid_drive_set(-24_in, 110);
  chassis.pid_wait();
  set_clamp = true;
  intake.move(-127);
  chassis.pid_turn_set(-90_deg, 110);
  chassis.pid_wait();
  intake.move(127);
  chassis.pid_drive_set(24_in, 110);
  chassis.pid_wait();
  chassis.pid_turn_set(-180_deg, 110);
  chassis.pid_wait();
  chassis.pid_drive_set(24_in, 110);
  chassis.pid_wait();
  chassis.pid_turn_set(-45_deg, 110);
  chassis.pid_wait();
  chassis.pid_drive_set(24_in, 110);
  chassis.pid_wait();
}
#pragma endregion
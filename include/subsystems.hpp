#pragma once

#include "EZ-Template/drive/drive.hpp"
#include "constants.hpp"
#include "intake.hpp"
#include "clamp.hpp"
#include "lady_brown.hpp"
#include "pros/adi.hpp"

namespace StratusQuo
{
    inline ez::Drive chassis(
        // These are your drive motors, the first motor is used for sensing!
        {-11, -16, 13},     // Left Chassis Ports (negative port will reverse it!)
        {17, 18, -20},  // Right Chassis Ports (negative port will reverse it!)

        19,      // IMU Port
        2.75,  // Wheel Diameter (Remember, 4" wheels without screw holes are actually 4.125!)
        450);   // Wheel RPM

    inline Intake intake(bottom_intake_port, top_intake_port, intake_piston_port);
    inline Clamp clamp(clamp_port);
    inline Lady_Brown lady_brown(left_lb_port, right_lb_port, lb_rotation_port,
                                 lady_brown_piston_port, pto);
    inline ez::Piston doinker(doinker_port);
    inline pros::adi::DigitalIn limit_switch(ls_port);
    inline ez::Piston ring_rush_mech(ring_rush_port, false);
    inline pros::Optical color_sensor(color_sensor_port);

    inline void default_constants() {
        // P, I, D, and Start I
        // https://ez-robotics.github.io/EZ-Template/tutorials/tuning_constants
        chassis.pid_heading_constants_set(9.95, 0, 40);
        chassis.pid_drive_constants_set(15, 0, 300);
        chassis.pid_turn_constants_set(2.95, 0, 20);
        chassis.pid_swing_constants_set(6, 0, 65);
        //chassis.pid_odom_angular_constants_set(6.5, 0.0, 52.5);    // Angular control for odom motions
        //chassis.pid_odom_boomerang_constants_set(5.8, 0.0, 32.5);  // Angular control for boomerang motions

        // Exit conditions
        // https://ez-robotics.github.io/EZ-Template/tutorials/tuning_exit_conditions
        chassis.pid_turn_exit_condition_set(70_ms, 3_deg, 200_ms, 7_deg, 250_ms, 500_ms);
        chassis.pid_swing_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 500_ms);
        chassis.pid_drive_exit_condition_set(30_ms, 1_in, 150_ms, 3_in, 225_ms, 300_ms);
        //chassis.pid_odom_turn_exit_condition_set(90_ms, 3_deg, 250_ms, 7_deg, 500_ms, 750_ms);
        //chassis.pid_odom_drive_exit_condition_set(90_ms, 1_in, 250_ms, 3_in, 500_ms, 750_ms);
        chassis.pid_turn_chain_constant_set(3_deg);
        chassis.pid_swing_chain_constant_set(5_deg);
        chassis.pid_drive_chain_constant_set(3_in);

        // Slew constants
        // https://ez-robotics.github.io/EZ-Template/tutorials/slew_constants
        chassis.slew_turn_constants_set(3_deg, 70);
        chassis.slew_drive_constants_set(3_in, 70);
        chassis.slew_swing_constants_set(3_in, 80);

        // The amount that turns are prioritized over driving in odom motions
        // - if you have tracking wheels, you can run this higher.  1.0 is the max
        /*chassis.odom_turn_bias_set(0.9);

        chassis.odom_look_ahead_set(7_in);           // This is how far ahead in the path the robot looks at
        chassis.odom_boomerang_distance_set(16_in);  // This sets the maximum distance away from target that the carrot point can be
        chassis.odom_boomerang_dlead_set(0.625);     // This handles how aggressive the end of boomerang motions are

        chassis.pid_angle_behavior_set(ez::shortest);  // Changes the default behavior for turning, this defaults it to the shortest path there
    */}
}
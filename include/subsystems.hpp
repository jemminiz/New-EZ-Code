#pragma once

#include "EZ-Template/drive/drive.hpp"
#include "drive.hpp"
#include "constants.hpp"
#include "intake.hpp"
#include "clamp.hpp"
#include "lady_brown.hpp"

namespace StratusQuo
{
    inline ez::Drive drive(
        // These are your drive motors, the first motor is used for sensing!
        {-11, -16, 13},     // Left Chassis Ports (negative port will reverse it!)
        {17, 18, -20},  // Right Chassis Ports (negative port will reverse it!)

        10,      // IMU Port
        2.75,  // Wheel Diameter (Remember, 4" wheels without screw holes are actually 4.125!)
        450);   // Wheel RPM
    inline StratusQuo::Drive chassis(*new ez::Drive({-11, -16, 13},     // Left Chassis Ports (negative port will reverse it!)
        {17, 18, -20},  // Right Chassis Ports (negative port will reverse it!)

        10,      // IMU Port
        2.75,  // Wheel Diameter (Remember, 4" wheels without screw holes are actually 4.125!)
        450), left_ls_port, right_ls_port);

    inline Intake intake(intake_motor_port, pto_motor_port, intake_piston_port);
    inline Clamp clamp(clamp_port);
    inline Lady_Brown lady_brown(left_lb_port, right_lb_port, lady_brown_piston_port, pto);
    //inline pros::adi::DigitalIn limit_switch(limit_switch_port);
};
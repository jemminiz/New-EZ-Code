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
    inline pros::adi::DigitalIn left_limit_switch(left_ls_port);
    inline pros::adi::DigitalIn right_limit_switch(left_ls_port);
};
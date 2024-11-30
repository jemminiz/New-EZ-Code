#pragma once

#include "EZ-Template/drive/drive.hpp"
#include "constants.hpp"
#include "intake.hpp"
#include "clamp.hpp"
#include "lady_brown.hpp"

namespace StratusQuo
{
    inline ez::Drive chassis(
        // These are your drive motors, the first motor is used for sensing!
        {1, 2, 3},     // Left Chassis Ports (negative port will reverse it!)
        {-4, -5, -6},  // Right Chassis Ports (negative port will reverse it!)

        21,      // IMU Port
        2.75,  // Wheel Diameter (Remember, 4" wheels without screw holes are actually 4.125!)
        450);   // Wheel RPM
    inline Intake intake(intake_motor_port, pto_motor_port, pto_port);
    inline Clamp clamp(clamp_port);
    inline Lady_Brown lady_brown(lady_brown_port, lady_brown_piston_port);
};
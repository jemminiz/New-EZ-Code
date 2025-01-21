#pragma once

#include "EZ-Template/piston.hpp"
#include "pros/motors.hpp"
namespace StratusQuo
{
    class Intake
    {
        public:
            Intake(int bottom_motor, int top_motor, uint8_t piston);
            ~Intake();
            bool toggle();
            int move(int voltage);
            int brake();
            int move_roller_motor(int voltage);
            pros::Motor get_bottom_motor();
            pros::Motor get_hook_motor();
        private:
            pros::Motor _roller_motor;
            pros::Motor _hook_motor;
            ez::Piston _piston;
    };
}
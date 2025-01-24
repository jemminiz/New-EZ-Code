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
            int move_bottom_motor(int voltage);
            pros::Motor &get_hook_motor();
            pros::Motor &get_roller_motor();
        private:
            pros::Motor _bottom_motor;
            pros::Motor _top_motor;
            ez::Piston _piston;
    };
}
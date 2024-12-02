#pragma once

#include "EZ-Template/piston.hpp"
#include "pros/motors.hpp"
namespace StratusQuo
{
    class Intake
    {
        public:
            Intake(int motor, int pto_motor, uint8_t piston);
            ~Intake();
            bool toggle();
            int move(int voltage);
            int brake();
        private:
            pros::Motor _bottom_motor;
            pros::Motor _top_motor;
            ez::Piston _piston;
    };
}
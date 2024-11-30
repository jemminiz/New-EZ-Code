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
        private:
            pros::Motor _normal_motor;
            pros::Motor _pto_motor;
            ez::Piston _piston;
    };
}
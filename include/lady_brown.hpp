#pragma once

#include "EZ-Template/piston.hpp"
#include "pros/motors.hpp"
namespace StratusQuo
{
    class Lady_Brown
    {
        public:
            Lady_Brown(int motor_port, uint8_t piston_port);
            int move(int voltage);
            bool toggle();
        private:
            pros::Motor _motor;
            ez::Piston _piston;
    };
}
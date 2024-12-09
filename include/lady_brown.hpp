#pragma once

#include "EZ-Template/piston.hpp"
#include "pros/motors.hpp"
namespace StratusQuo
{
    class Lady_Brown
    {
        public:
            Lady_Brown(int left_motor_port, int right_motor_port, int rotation_port, uint8_t piston_port, uint8_t pto_port);
            int move(int voltage);
            int toggle();
            int set_load_state(bool state);
            bool get_load_state();
            int brake();
            
            
        // PTO Logic

            /* sets pto values
             * @param input 
             * true to activate lady brown, false to activate drivetrain
             */
            int set_pto(bool input);

            // returns true if lb is active
            bool is_pto();
        private:
            pros::Motor _left_motor;
            pros::Motor _right_motor;
            ez::Piston _piston;
            pros::Rotation _rotation_sensor;

            // PTO Logic
            ez::Piston _pto;
            bool _pto_state; // true == dt, false == lb
    };
}
#pragma once

#include "EZ-Template/piston.hpp"
#include "pros/motors.hpp"
namespace StratusQuo
{
    class Lady_Brown
    {
        public:
            Lady_Brown(int left_motor_port, int right_motor_port, uint8_t piston_port, uint8_t left_pto_port, uint8_t right_pto_port);
            int move(int voltage);
            int toggle();
            int set_load_state(bool state);
            bool get_load_state();
            int brake();
            
            // PTO Logic
            int set_pto(bool input);
            bool get_pto();
        private:
            pros::Motor _left_motor;
            pros::Motor _right_motor;
            ez::Piston _piston;

            // PTO Logic
            int _set_left_side_pto(bool input);
            int _set_right_side_pto(bool input);
            ez::Piston _left_side_pto;
            ez::Piston _right_side_pto;
            bool _pto_state; // If true, LB is PTO'd, otherwise it's DT
    };
}
#include "lady_brown.hpp"

StratusQuo::Lady_Brown::Lady_Brown(int left_motor_port, int right_motor_port, uint8_t piston_port, uint8_t left_pto_port, uint8_t right_pto_port) :
_left_motor(left_motor_port), _right_motor(right_motor_port), _piston(piston_port), _left_side_pto(left_pto_port),
_right_side_pto(right_pto_port)
{}

int StratusQuo::Lady_Brown::move(int voltage)
{
    _left_motor.move(voltage);
    _right_motor.move(voltage);
    return 0;
}

int StratusQuo::Lady_Brown::toggle()
{
    _piston.set(!_piston.get());
    return 0;
}

int StratusQuo::Lady_Brown::set_load_state(bool state)
{
    _piston.set(state);
    return 0;
}

bool StratusQuo::Lady_Brown::get_load_state()
{
    return _piston.get();
}

int StratusQuo::Lady_Brown::brake()
{
    _left_motor.brake();
    _right_motor.brake();
    return 0;
}

// PTO Logic
int StratusQuo::Lady_Brown::_set_left_side_pto(bool input)
{
    _left_side_pto.set(input);
    return 0;
}
int StratusQuo::Lady_Brown::_set_right_side_pto(bool input)
{
    _right_side_pto.set(input);
    return 0;
}

bool StratusQuo::Lady_Brown::get_pto()
{
    if(_right_side_pto.get() == _left_side_pto.get())
        return _right_side_pto.get();
    return false;
}
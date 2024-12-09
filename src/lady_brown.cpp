#include "lady_brown.hpp"

StratusQuo::Lady_Brown::Lady_Brown(int left_motor_port, int right_motor_port, int rotation_port, uint8_t piston_port, uint8_t pto_port) :
_left_motor(left_motor_port), _right_motor(right_motor_port), _rotation_sensor(rotation_port),
_piston(piston_port), _pto(pto_port, false)
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
int StratusQuo::Lady_Brown::set_pto(bool input)
{
    // intent - true == lb
    _pto.set(!input); // Check logic - should work?
    return 0;
}

bool StratusQuo::Lady_Brown::is_pto()
{
    return !_pto.get(); // I think this is right I'm not even sure
}
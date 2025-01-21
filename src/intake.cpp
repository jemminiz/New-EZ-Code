#include "intake.hpp"
StratusQuo::Intake::Intake(int bottom, int top, uint8_t piston) : _roller_motor(bottom), _hook_motor(top), _piston(piston)
{}
StratusQuo::Intake::~Intake()
{
    delete &_roller_motor;
    delete &_hook_motor;
    delete &_piston;
}

bool StratusQuo::Intake::toggle()
{
    _piston.set(!_piston.get());
    return _piston.get();
}

int StratusQuo::Intake::move(int voltage)
{
    _roller_motor.move(voltage);
    _hook_motor.move(voltage);
    return 0;
}

int StratusQuo::Intake::brake()
{
    _roller_motor.brake();
    _hook_motor.brake();
    return 0;
}

int StratusQuo::Intake::move_roller_motor(int voltage)
{
    _roller_motor.move(voltage);
    return 0;
}

pros::Motor StratusQuo::Intake::get_bottom_motor()
{
    return _roller_motor;
}

pros::Motor StratusQuo::Intake::get_hook_motor()
{
    return _hook_motor;
}
#include "intake.hpp"
StratusQuo::Intake::Intake(int bottom, int top, uint8_t piston) : _bottom_motor(bottom), _top_motor(top), _piston(piston)
{}
StratusQuo::Intake::~Intake()
{
    delete &_bottom_motor;
    delete &_top_motor;
    delete &_piston;
}

bool StratusQuo::Intake::toggle()
{
    _piston.set(!_piston.get());
    return _piston.get();
}

int StratusQuo::Intake::move(int voltage)
{
    _bottom_motor.move(voltage);
    _top_motor.move(voltage);
    return 0;
}

int StratusQuo::Intake::brake()
{
    _bottom_motor.brake();
    _top_motor.brake();
    return 0;
}
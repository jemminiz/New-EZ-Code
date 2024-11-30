#include "intake.hpp"
StratusQuo::Intake::Intake(int motor, int pto_motor, uint8_t piston) : _normal_motor(motor), _pto_motor(pto_motor), _piston(piston)
{}
StratusQuo::Intake::~Intake()
{
    delete &_normal_motor;
    delete &_pto_motor;
    delete &_piston;
}

bool StratusQuo::Intake::toggle()
{
    _piston.set(!_piston.get());
    return _piston.get();
}
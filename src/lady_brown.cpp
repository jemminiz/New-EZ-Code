#include "lady_brown.hpp"

StratusQuo::Lady_Brown::Lady_Brown(int motor_port, uint8_t piston_port) : _motor(motor_port), _piston(piston_port)
{}

int StratusQuo::Lady_Brown::move(int voltage)
{
    _motor.move(voltage);
    return 0;
}

bool StratusQuo::Lady_Brown::toggle()
{
    _piston.set(!_piston.get());
    return _piston.get();
}

#include "clamp.hpp"

StratusQuo::Clamp::Clamp(uint8_t port) : _piston(port)
{}

int StratusQuo::Clamp::toggle(int toggle)
{
    _piston.button_toggle(toggle);
    return 0;
}

int StratusQuo::Clamp::set(bool value)
{
    _piston.set(value);
    return 0;
}
#include "clamp.hpp"

StratusQuo::Clamp::Clamp(uint8_t port) : _piston(port)
{}

int StratusQuo::Clamp::set_toggle(int toggle)
{
    _piston.button_toggle(toggle);
    return 0;
}

int StratusQuo::Clamp::set(bool value)
{
    _piston.set(value);
    _current_state = value;
    return 0;
}

int StratusQuo::Clamp::toggle()
{
    _piston.set(!_current_state);
    _current_state = !_current_state;
    return 0;
}
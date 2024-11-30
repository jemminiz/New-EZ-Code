#include "clamp.hpp"

StratusQuo::Clamp::Clamp(uint8_t port) : _piston(port)
{}

bool StratusQuo::Clamp::toggle()
{
    _piston.set(!_piston.get());
    return _piston.get();
}
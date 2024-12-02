#pragma once

#include <cstdint>
#include "EZ-Template/piston.hpp"
namespace StratusQuo
{
    class Clamp
    {
        public:
            Clamp(uint8_t port);
            int toggle(int toggle);
            int set(bool value);
        private:
            ez::Piston _piston;
    };
}
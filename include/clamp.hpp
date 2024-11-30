#pragma once

#include <cstdint>
#include "EZ-Template/piston.hpp"
namespace StratusQuo
{
    class Clamp
    {
        public:
            Clamp(uint8_t port);
            bool toggle();
        private:
            ez::Piston _piston;
    };
}
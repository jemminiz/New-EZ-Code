#pragma once

#include <cstdint>
#include "EZ-Template/piston.hpp"
namespace StratusQuo
{
    class Clamp
    {
        public:
            Clamp(uint8_t port);
            int set_toggle(int toggle);
            int set(bool value);
            int toggle();
        private:
            ez::Piston _piston;
            bool _current_state = false;
    };
}
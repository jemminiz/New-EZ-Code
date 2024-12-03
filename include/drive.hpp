#include "EZ-Template/drive/drive.hpp"
#include "pros/adi.hpp"

namespace StratusQuo
{
    class Drive : public ez::Drive
    {
        public:
            Drive(ez::Drive chassis, uint8_t left_ls_port, uint8_t right_ls_port);
            pros::adi::DigitalIn left_limit_switch;
            pros::adi::DigitalIn right_limit_switch;
    };
}
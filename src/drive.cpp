#include "drive.hpp"

StratusQuo::Drive::Drive(ez::Drive chassis, uint8_t left_ls_port, uint8_t right_ls_port)
: ez::Drive(chassis), left_limit_switch(left_ls_port), right_limit_switch(right_ls_port)
{};
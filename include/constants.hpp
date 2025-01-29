#pragma once

#include <cstdint>
#include <atomic>
namespace StratusQuo
{
    const int bottom_intake_port = 15;
    const int top_intake_port = 12;
    const int left_lb_port = 13;
    const int right_lb_port = 20;
    const int lb_rotation_port = 5;
    const int color_sensor_port = 9;
    const uint8_t intake_piston_port = 'e';
    const uint8_t clamp_port = 'h';
    const uint8_t lady_brown_piston_port = 'f';
    const uint8_t pto = 'g';
    const uint8_t ls_port = 'c';
    const uint8_t ring_rush_port = 'b';
    const uint8_t doinker_port = 'd';

    typedef enum
    {
        RED,
        BLUE
    } Color;
    inline Color team_color = RED;

    inline bool isColorSortEnabled = true;
    inline bool isAutoClampEnabled = true;

    const inline int RED_HUE_LOW = 0;
    const inline int RED_HUE_HIGH = 20;
    const inline int BLUE_HUE_LOW = 200;
    const inline int BLUE_HUE_HIGH = 240;

    inline std::atomic<bool> is_red(true);
    inline std::atomic<bool> running_sort(true);
    inline std::atomic<bool> set_clamp(false);
    inline std::atomic<bool> bad_color(false);
    inline std::atomic<bool> is_intake_up(false);
    inline std::atomic<double> roller_motor_speed = 0;
    inline std::atomic<double> hook_motor_speed = 0;

    inline int intake_speed_set(double roller_speed, double hook_speed)
    {
        roller_motor_speed.store(roller_speed);
        hook_motor_speed.store(hook_speed);
        return 0;
    }
    inline int get_roller_speed()
    {
        return roller_motor_speed.load();
    }
    inline int get_hook_speed()
    {
        return hook_motor_speed.load();
    }
}
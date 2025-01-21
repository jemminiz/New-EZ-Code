#pragma once
namespace StratusQuo
{
    void blue_side_goal_rush();
    void red_side_goal_rush();
    void red_side_fast_goal_rush();
    void blue_side_fast_goal_rush();

    void red_side_ring_rush();
    void blue_side_ring_rush();

    void solo_awp_left();
    void solo_awp_right();
    void half_awp();
    void awp_no_ring();
    void right_side_half_awp();

    void first_autonomous_skills();
    void second_autonomous_skills();


    void default_constants();
    void testing_pid_auto();

    inline bool set_clamp = false;

    typedef enum color_t
    {
        RED,
        BLUE
    } Color;
    inline Color team_color = RED; // Default to red bc of skills
} // namespace StratusQuo
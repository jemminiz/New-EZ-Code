// Intent - handle all robodash related code
#pragma once

#include "autons.hpp"
#include "robodash/api.h" // IWYU pragma: keep
#include "robodash/views/console.hpp"

inline rd::Selector selector(
{
  {"Solo AWP Left Side", StratusQuo::solo_awp_left},
  {"Solo AWP Right Side", StratusQuo::solo_awp_right},
  {"AWP No Second Goal", StratusQuo::half_awp},
  {"AWP No Alliance Stake Stack", StratusQuo::awp_no_ring},
  {"Right Half AWP", StratusQuo::right_side_half_awp},
  {"Blue Goal Rush", StratusQuo::blue_side_goal_rush},
  {"Red Goal Rush", StratusQuo::red_side_goal_rush},
  {"Blue Ring Rush", StratusQuo::blue_side_ring_rush},
  {"Red Ring Rush", StratusQuo::red_side_ring_rush},
  {"First Skills", StratusQuo::first_autonomous_skills},
  {"Second Skills", StratusQuo::second_autonomous_skills}
});

inline rd::Console console("Debug console");

//inline rd::Image image("assets/stratusquo.png");

inline void debug()
{
  console.focus();
  console.print("Hi guys!");
}
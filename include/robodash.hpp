// Intent - handle all robodash related code
#pragma once

#include "autons.hpp"
#include "robodash/api.h" // IWYU pragma: keep
#include "robodash/views/console.hpp"

inline rd::Selector selector(
{
  {"Solo AWP Left Side", solo_awp_left},
  {"Solo AWP Right Side", solo_awp_right},
  {"AWP No Second Goal", half_awp},
  {"AWP No Alliance Stake Stack", awp_no_ring},
  {"Right Half AWP", right_side_half_awp},
  {"Blue Goal Rush", blue_side_goal_rush},
  {"Red Goal Rush", red_side_goal_rush},
  {"Blue Ring Rush", blue_side_ring_rush},
  {"Red Ring Rush", red_side_ring_rush},
  {"First Skills", first_autonomous_skills},
  {"Second Skills", second_autonomous_skills}
});

inline rd::Console console("Debug console");

//inline rd::Image image("assets/stratusquo.png");

inline void debug()
{
  console.focus();
  console.print("Hello, world!");
}
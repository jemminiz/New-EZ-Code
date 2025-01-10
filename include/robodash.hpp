// Intent - handle all robodash related code

#include "autons.hpp"
#include "robodash/api.h" // IWYU pragma: keep
inline rd::Selector selector(
{
  {"Solo AWP", solo_awp},
  {"AWP No Second Goal", half_awp},
  {"AWP No Alliance Stake Stack", awp_no_ring},
  {"Right Half AWP", right_side_half_awp},
  {"Blue Goal Rush", blue_side_goal_rush},
  {"Red Goal Rush", red_side_goal_rush},
  {"Blue Ring Rush", blue_side_ring_rush},
  {"Red Ring Rush", red_side_ring_rush}
});
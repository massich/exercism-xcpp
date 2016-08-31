#include "leap.h"

bool leap::is_leap_year (int year)
{
  auto is_divisible = [year](int y) { return year%y == 0;};

  if (is_divisible(400))
    return true;
  else
    return (is_divisible(4) && !is_divisible(100));
}

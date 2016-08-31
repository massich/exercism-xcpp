#include "hamming.h"
#include <stdexcept>
#include <algorithm>

::size_t hamming::compute(const std::string& s, const std::string& z)
{
  if ( s.length() != z.length() ) throw new std::domain_error("unequal length");
  auto z_it = z.begin();
  auto my_comparison = [&](::size_t sum, char x) { return sum + (x != *z_it++); };
  return accumulate( s.begin(), s.end(), 0, my_comparison);
}

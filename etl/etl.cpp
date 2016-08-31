#include <iostream>
#include <utility>
#include "etl.h"

std::map<char, int> etl::transform(std::map<int, std::vector<char> > old_format)
{
  std::map<char, int> new_format;
  for (auto const &entry : old_format)
    for (auto const &letter : entry.second)
      new_format.emplace(tolower(letter), entry.first);

  return new_format;
}

#include "prime_factors.h"
#include <algorithm>
#include <math.h>
#include <iostream>

std::vector<int> get_prime_numbers_until(int const max)
{
  std::vector<int> prime_numbers{2,3};
  for (auto ii=5; ii<=max; ii+=2 )
    prime_numbers.push_back(ii);

  for (auto p=prime_numbers.begin(); p!=prime_numbers.end(); ++p)
  {
    auto new_end = std::remove_if ( p+1,
                                    prime_numbers.end(),
                                    [=] (int ii) { return ii%(*p)==0; }
                                  );
    prime_numbers.erase(new_end, prime_numbers.end());
  }

  return prime_numbers;
}

std::vector<int> prime_factors::of (int val)
{
  int const sierve_max = ceil(sqrt(val));
  auto sierve = get_prime_numbers_until(sierve_max);
  auto factor = sierve.begin();

  std::vector<int> factors;
  while ( factor != sierve.end() && val > 1)
  {
    if ( val % (*factor) == 0)
      {
        factors.push_back(*factor);
        val /= *factor;
      }
    else
      ++factor;
  }
  if ( val > 1)
    factors.push_back(val);

  return factors;
}

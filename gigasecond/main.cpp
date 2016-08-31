#include "gigasecond.h"
#include <iostream>

int main()
{
  gigasecond::advance();
  boost::gregorian::date x = gigasecond::advance2();
  std::cout << "main " << x << std::endl;
  std::cout << "main " << gigasecond::advance3(x) << std::endl;
  return 0;
}

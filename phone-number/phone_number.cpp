#include "phone_number.h"
#include <algorithm>         // std::copy
#include <iterator>          // std::back_insert
#include <cctype>            // std::isdigit

namespace{
  std::string get_digits( std::string const &s )
  {
    std::string digits;
    std::copy_if( s.begin(), s.end(),
                  std::back_inserter(digits),
                  ::isdigit);

    if ( digits.length() == 10 )
      return digits;

    if ( digits.length() == 11 && digits[0] == '1')
      return digits.substr(1);

    return "0000000000";
  }
}

phone_number::phone_number(std::string const &s): _digits(get_digits(s)) { }

std::string const phone_number::area_code() const
{
  return _digits.substr(0, 3);
}

std::string const phone_number::exchange_code() const
{
  return _digits.substr(3, 3);
}

std::string const phone_number::extension_code() const
{
  return _digits.substr(6);
}

std::string const phone_number::number() const
{
  return _digits;
}

phone_number::operator std::string() const
{
  return "(" + area_code() + ") " + exchange_code() + "-" + extension_code();
}

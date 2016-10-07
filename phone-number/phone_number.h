#pragma once
#include <string>
#include <vector>

class phone_number
{
public:
  phone_number(std::string const &s);
  std::string const area_code() const;
  std::string const number() const;
  operator std::string() const;
private:
  std::string const exchange_code() const;
  std::string const extension_code() const;
  std::string const _digits;
};

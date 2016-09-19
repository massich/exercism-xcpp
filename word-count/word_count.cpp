#include <cwctype>
#include <sstream>
#include <algorithm>
#include "word_count.h"


std::map<std::string, int> word_count::words(std::basic_string<char> const &s)
{
  std::istringstream iss{s};
  std::map<std::string, int> word_occurrences;
  std::string crr_word;

  while ( iss >> crr_word )
    {
      std::transform(crr_word.begin(), crr_word.end(), crr_word.begin(), ::tolower);
      auto it = word_occurrences.find(crr_word);
      if (it != word_occurrences.end())
         it->second++;
      else
        word_occurrences.emplace(crr_word, 1);
    }

  return word_occurrences;
}

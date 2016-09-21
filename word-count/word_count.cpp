#include <cwctype>
#include <sstream>
#include <algorithm>
#include <regex>
#include "word_count.h"


std::map<std::string, int> word_count::words(std::basic_string<char> const &s)
{
  std::regex const words_regex{"\\w(?:[\\w']*\\w)?"};
  auto words_begin = std::sregex_iterator(s.begin(), s.end(), words_regex);
  auto words_end = std::sregex_iterator();
  std::map<std::string, int> word_occurrences;

  for (auto words_it = words_begin; words_it != words_end; ++words_it)
    {
      std::string crr_word = words_it->str();
      std::transform(crr_word.begin(), crr_word.end(), crr_word.begin(), ::tolower);

      auto it = word_occurrences.find(crr_word);
      if (it != word_occurrences.end())
         it->second++;
      else
        word_occurrences.emplace(crr_word, 1);
    }

  return word_occurrences;
}

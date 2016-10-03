#include "anagram.h"
#include <iostream>
#include <utility>
#include <clocale>

template<typename T1, typename T2>
std::ostream &operator<<(std::ostream &stream, const std::map<T1, T2>& map)
{
  for (typename std::map<T1, T2>::const_iterator it = map.begin();
       it != map.end();
       ++it)
    {
      stream << (*it).first << " --> " << (*it).second << std::endl;
    }
  return stream;
}

std::map<char, int> compute_histogram( const std::string & s)
{
  std::map<char,int> my_hist;
  for (char leter : s)
  {
    leter = std::tolower(leter);
    auto it = my_hist.find(leter);
    if (it == my_hist.end())
        my_hist[leter]=1;
    else
        it->second++;
  }
  // std::cout << "COMPUTE HISTOGRAM:\n input: " << s << std::endl;
  // std::cout << my_hist;
  return my_hist;
}

anagram::anagram::anagram(const std::string &s): word_hist(compute_histogram(s)) {};


std::vector<std::string> anagram::anagram::matches(const std::vector<std::string> & candidates) const
{
  std::vector <std::string> valid_anagrams;

  for (const auto &cand : candidates)
  {
    const auto candidate_histogram = compute_histogram(cand);
    if (candidate_histogram == word_hist)
      valid_anagrams.push_back(cand);
  }
  // std::cout << "[" << word_hist << "]  These are the candidates: {";
  // for (auto const &c : candidates)
  //   std::cout << c << ", ";
  // std::cout << "} --> {";
  // for (auto const &v : valid_anagrams)
  //   std::cout << v << ", ";
  // std::cout << "}\n";
  return valid_anagrams;
}

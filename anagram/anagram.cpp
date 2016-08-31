#include "anagram.h"
#include <iostream>
#include <utility>

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
  for (const auto& leter : s)
  {
    auto it = my_hist.find(leter);
    if (it == my_hist.end())
        my_hist[leter]=1;
    else
        it->second++;
  }
  return my_hist;
}

anagram::anagram::anagram(const std::string &s): word_hist(compute_histogram(s)) {};


std::vector<std::string> anagram::anagram::matches(const std::vector<std::string> & candidates)
{
  std::vector <std::string> valid_anagrams;

  for (auto &cand : candidates)
  {
    auto candidate_histogram = compute_histogram(cand);
    bool is_valid = true;
    for( auto it=candidate_histogram.begin();
         it!=candidate_histogram.end();
         ++it)
    {
       if (word_hist[it->first] != it->second){
         is_valid = false;
         break;
       }
    }
    if (is_valid)
      valid_anagrams.push_back(cand);
  }

  return valid_anagrams;
}

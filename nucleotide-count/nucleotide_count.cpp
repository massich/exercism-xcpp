#include "nucleotide_count.h"

dna::counter dna::counter( std::string const &seq )
{

  for (auto c : seq)
  {
    auto it = occurrences.find(c);
    if (it != occurrences.end())
      it->second++;
    else
      occurrences.emplace(c,1);
  }
}

Collection dna::counter::nucleotide_counts( const std::string &s){
  return { {'A', 0}, {'T', 0}, {'C', 0}, {'G', 0} };
}
int dna::counter::count(const char &c){
  return 0;
}

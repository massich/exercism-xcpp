#include "nucleotide_count.h"

dna::counter::counter ( std::string const &seq ):
  occurrences({ {'A', 0}, {'T', 0}, {'C', 0}, {'G', 0} })
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

dna::Collection dna::counter::nucleotide_counts() const {
  return occurrences;
}
int dna::counter::count(const char &c){
  return 0;
}

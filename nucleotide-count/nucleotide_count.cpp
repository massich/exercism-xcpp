#include "nucleotide_count.h"
#include <iostream>
#include <exception>

dna::counter::counter ( std::string const &seq ):
  occurrences({ {'A', 0}, {'T', 0}, {'C', 0}, {'G', 0} })
{
  for (auto const c : seq)
    add_occurrence(c);
}

dna::Collection dna::counter::nucleotide_counts() const {
  return occurrences;
}

void dna::counter::add_occurrence( char const c)
{
  auto it = occurrences.find(c);
  if (it != occurrences.end())
    it->second++;
  else
    occurrences.emplace(c,1);
}

int dna::counter::count(char const c) const{
  
  auto it = occurrences.find(c);
  if (it == occurrences.end())
    throw std::invalid_argument("invalid argument. Parameter c should be a valid nuclotide");
  else
    return it->second;
}

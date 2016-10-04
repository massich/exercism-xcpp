#include <map>

namespace dna{
  using Collection = std::map< const char, int >;

  class counter {
  public:
    counter( std::string const &seq );
    Collection nucleotide_counts() const;
    int count(char const c) const;
  private:
    Collection occurrences;
    void add_occurrence(char const c);
  };

}

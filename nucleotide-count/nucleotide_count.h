#include <map>

namespace dna{
  using Collection = std::map< const char, int >;

  class counter {
  public:
    counter( std::string const &seq );
    Collection nucleotide_counts();
    int count(const char &c);
  private:
    Collection occurrences;
  };

}

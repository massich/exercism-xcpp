#include <string>
#include <map>
#include <vector>

namespace anagram{
class anagram{
 public:
  anagram(const std::string &s);
  std::vector<std::string> matches(const std::vector<std::string> & candidates) const;
 // private:
  std::map<char,int> word_hist;
};
}

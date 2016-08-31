#include "bob.h"
#include <regex>
#include <algorithm>


std::string question_answer() { return "Sure.";}
std::string yell_answer() { return "Whoa, chill out!";}
std::string silence_answer() { return "Fine. Be that way!";}
std::string default_answer() { return "Whatever.";}

bool is_question(const std::string q){
  return std::regex_match( q, std::regex("\\s?$"));
}
bool is_yell(const std::string q){
  size_t count_upper = count_if(q.begin(), q.end(),    
                                [](unsigned char ch) { return isupper(ch); });
  return count_upper > (q.length()/2);
}

bool is_silence(const std::string q){
  return std::regex_match( q, std::regex("\\s+"));
}

std::string bob::hey(const std::string q){
  if (is_silence(q)) return silence_answer();
  if (is_yell(q)) return yell_answer();
  if (is_question(q)) return question_answer();
  return default_answer();
}

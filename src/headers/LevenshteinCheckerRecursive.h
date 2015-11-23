#ifndef LEVENSHTEIN_CHECKER_RECURSIVE_H
#define LEVENSHTEIN_CHECKER_RECURSIVE_H

#include <string>
#include <vector>

#include "FileReader.h"
#include "Dictionary.h"

class LevenshteinCheckerRecursive: public LevenshteinChecker {
private:
  FileReader* fileReader;
  Dictionary* dictionary;
  int levenshteinDistance(std::string s, int len_s, std::string t, int len_t, int max_depth);
  std::vector<std::string>* parsedStrings;
  int min(int i, int j, int k);

public:
  ~LevenshteinCheckerRecursive();
  LevenshteinCheckerRecursive(Dictionary* dict, FileReader* fileReader);
  void checkAgainstDictionary(void);


};


#endif

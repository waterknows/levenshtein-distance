#ifndef LEVENSHTEIN_CHECKER_DYNAMIC_H
#define LEVENSHTEIN_CHECKER_DYNAMIC_H

#include <string>
#include <vector>

#include "FileReader.h"
#include "Dictionary.h"

class LevenshteinCheckerDynamic: public LevenshteinChecker {
private:
  FileReader* fileReader;
  Dictionary* dictionary;
  int levenshteinDistance(std::string s, std::string t);
  std::vector<std::string>* parsedStrings;
  int min(int i, int j, int k);

public:
  ~LevenshteinCheckerDynamic();
  LevenshteinCheckerDynamic(Dictionary* dict, FileReader* fileReader);
  void checkAgainstDictionary(void);


};


#endif

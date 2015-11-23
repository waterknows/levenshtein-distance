#include <iostream>

#include "../headers/LevenshteinChecker.h"
#include "../headers/LevenshteinCheckerRecursive.h"



LevenshteinCheckerRecursive::LevenshteinCheckerRecursive(Dictionary* dict, FileReader* fileReader) {
  this->fileReader = fileReader;
  this->dictionary = dict;
  parsedStrings = new std::vector<std::string>();
}

LevenshteinCheckerRecursive::~LevenshteinCheckerRecursive() {
  delete parsedStrings;
}

int LevenshteinCheckerRecursive::min(int i, int j, int k) {
  if (k < i && k < j) return k;
  if (j < i && j < k) return j;
  return i;
}

int LevenshteinCheckerRecursive::levenshteinDistance(std::string s, int len_s, std::string t, int len_t, int max_depth) {
  //algorithm from: https://en.wikipedia.org/wiki/Levenshtein_distance

  if (max_depth < 0) {
    return 9999; //recursion failed!
  }

  int cost = 0;

  if (len_s <= 0) return len_t;
  if (len_t <= 0) return len_s;

  if (s[len_s] == t[len_s]) {
    cost = 0;
  }
  else {
    cost = 1;
  }

  return min(levenshteinDistance(s, len_s - 1, t, len_t, max_depth-1) + 1,
            levenshteinDistance(s, len_s, t, len_t - 1, max_depth-1) + 1,
            levenshteinDistance(s, len_s - 1, t, len_t -1, max_depth-1) + cost);
}

void LevenshteinCheckerRecursive::checkAgainstDictionary(void) {
  // if (!fileReader->isFileStillOpen() || fileReader->getUnparsedStringSize()) {
  //   return;
  // }

  std::string line = fileReader->getUnparsedString();
  if (line.length() < 1) {
    return;
  }

  int size = 10;
  int scores[size];
  std::string values[size];
  for (int i = 0; i < size; i++) {
    scores[i] = 1000; //initialize array to some unachievable distance
  }

  int stepSize = 1000; //for perfomance reasons. The recursive check is kinda crappy
  for (int i = 0; i < dictionary->getSize(); i+=stepSize) {
    std::string dictWord = dictionary->getWord(i);
    int score = levenshteinDistance(line, line.length() - 1, dictWord, dictWord.length() - 1, 10);
    for (int j = 0; j < size; j++) {
      if (score < scores[j]) {
        scores[j] = score;
        values[j] = dictWord;
        break;
      }
    }
  }

  std::cout << std::endl;

  for (int i = 0; i < size; i++) {
    std::cout << line << " " << values[i] << " " << scores[i] << '\n';
  }

}

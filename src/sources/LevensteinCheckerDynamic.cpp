#include <iostream>

#include "../headers/LevenshteinChecker.h"
#include "../headers/LevenshteinCheckerDynamic.h"



LevenshteinCheckerDynamic::LevenshteinCheckerDynamic(Dictionary* dict, FileReader* fileReader) {
  this->fileReader = fileReader;
  this->dictionary = dict;
  parsedStrings = new std::vector<std::string>();
}

LevenshteinCheckerDynamic::~LevenshteinCheckerDynamic() {
  delete parsedStrings;
}

int LevenshteinCheckerDynamic::min(int i, int j, int k) {
  if (k < i && k < j) return k;
  if (j < i && j < k) return j;
  return i;
}

int LevenshteinCheckerDynamic::levenshteinDistance(std::string s, std::string t) {
  //algorithm from: https://en.wikipedia.org/wiki/Levenshtein_distance

  // base cases
  if (s == t) return 0;
  if (s.length() <= 0) return t.length();
  if (t.length() <= 0) return s.length();

  // create two work vectors of integer distances
  int array_length = t.length() + 1;
  int v0[array_length];
  int v1[array_length];

  // initialize v0 (the previous row of distances)
  // this row is A[0][i]: edit distance for an empty s
  // the distance is just the number of characters to delete from t
  for (int i = 0; i < array_length; i++) {
      v0[i] = i;
    }

  for (int i = 0; i < s.length(); i++)
  {
      // calculate v1 (current row distances) from the previous row v0

      // first element of v1 is A[i+1][0]
      //   edit distance is delete (i+1) chars from s to match empty t
      v1[0] = i + 1;

      // use formula to fill in the rest of the row
      for (int j = 0; j < t.length(); j++)
      {
          int cost = (s[i] == t[j]) ? 0 : 1;
          v1[j + 1] = min(v1[j] + 1, v0[j + 1] + 1, v0[j] + cost);
      }

      // copy v1 (current row) to v0 (previous row) for next iteration
      for (int j = 0; j < array_length; j++)
          v0[j] = v1[j];
  }

  return v1[t.length()];
}

void LevenshteinCheckerDynamic::checkAgainstDictionary(void) {
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

  int stepSize = 1; //for perfomance reasons. The recursive check is kinda crappy
  for (int i = 0; i < dictionary->getSize(); i+=stepSize) {
    std::string dictWord = dictionary->getWord(i);
    int score = levenshteinDistance(line, dictWord);
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

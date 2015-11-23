#ifndef LEVENSHTEIN_CHECKER_H
#define LEVENSHTEIN_CHECKER_H

class LevenshteinChecker {

public:
  virtual ~LevenshteinChecker() {};
  virtual void checkAgainstDictionary(void) = 0; //grabs a single string from the
  //filereader and compares it against all(?) values in the dictionary.
  //adds the original string to the internal vector and the next X strings with close scores.

  /*
  internal struct should look like:
  [original_string, [score, string; score, string...]]
  */


};


#endif

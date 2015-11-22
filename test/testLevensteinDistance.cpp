#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE FileReaderStdOut
#include <boost/test/included/unit_test.hpp>

#include <iostream>
#include <string>

int min(int i, int j, int k) {

  if (k < i && k < j) {
    return k;
  }
  if (j < i && j < k) {
    return j;
  }
  return i;
}


int recursiveLevenshtein(std::string s, int len_s, std::string t, int len_t) {
  //algorithm from: https://en.wikipedia.org/wiki/Levenshtein_distance

  int cost = 0;

  if (len_s == 0) return len_t;
  if (len_t == 0) return len_s;

  if (s[len_s] == t[len_s]) {
    cost = 0;
  }
  else {
    cost = 1;
  }

  return min(recursiveLevenshtein(s, len_s - 1, t, len_t) + 1,
            recursiveLevenshtein(s, len_s, t, len_t - 1) + 1,
            recursiveLevenshtein(s, len_s - 1, t, len_t -1) + cost);
}

int LevenshteinTwoRows(std::string s, std::string t) {
  //algorithm from: https://en.wikipedia.org/wiki/Levenshtein_distance

  // base cases
  if (s == t) return 0;
  if (s.length() == 0) return t.length();
  if (t.length() == 0) return s.length();

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

BOOST_AUTO_TEST_CASE(test_recursive) {
  std::string testString = "kitten";
  std::string referenceString = "sitting";

  std::cout << "starting" << '\n';
  int val = recursiveLevenshtein(testString, testString.length(),
   referenceString, referenceString.length());
  std::cout << val << '\n';
  std::cout << "ending" << '\n';

  BOOST_CHECK(3 == val);
}

BOOST_AUTO_TEST_CASE(test_dynamic) {
  std::string testString = "kitten";
  std::string referenceString = "sitting";

  std::cout << "starting" << '\n';
  int val = LevenshteinTwoRows(testString, referenceString);
  std::cout << val << '\n';
  std::cout << "ending" << '\n';

  BOOST_CHECK(3 == val);
}

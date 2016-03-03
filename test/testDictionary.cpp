#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Dictionary
#include <boost/test/included/unit_test.hpp>

#include <iostream>
#include <string>

#include "../src/headers/Dictionary.h"
#include "../src/sources/Dictionary.cpp"

BOOST_AUTO_TEST_CASE(testDictionary) {
  Dictionary* d = new Dictionary("config/dictionary.txt");

  //these tests are kinda bad. They are very fragile.
  BOOST_CHECK(d->getSize() >= 99171);
  BOOST_CHECK(d->getWord(1020) == "Asmara");
}

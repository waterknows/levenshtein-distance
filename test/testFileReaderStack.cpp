#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE FileReaderStdOut
#include <boost/test/included/unit_test.hpp>

#include <iostream>
#include <string>

#include "../src/headers/FileReader.h"
#include "../src/headers/FileReaderStack.h"
#include "../src/sources/FileReaderStack.cpp"

BOOST_AUTO_TEST_CASE(testFileReaderStdOut) {
  FileReaderStack* f = new FileReaderStack("/home/jeff/levenshtein-c/bin/test.txt");
  std::cout << f->getFilePath() << std::endl;

  f->readLine();

  std::stack<std::string>* frstack = f->getStack();

  int i = frstack->size();

  std::string testString = frstack->top();
  frstack->pop();

  int j = frstack->size();

  BOOST_CHECK(i == 1);
  BOOST_CHECK(j == 0);
}

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE FileReaderStack
#include <boost/test/included/unit_test.hpp>

#include <iostream>
#include <string>

#include "../src/headers/FileReader.h"
#include "../src/headers/FileReaderStack.h"
#include "../src/sources/FileReaderStack.cpp"

BOOST_AUTO_TEST_CASE(testFileReaderStdOut) {
  FileReaderStack* f = new FileReaderStack("test.txt");
  std::cout << f->getFilePath() << std::endl;

  f->readLine();

  int i = f->getUnparsedStringSize();

  f->readLine();

  int j = f->getUnparsedStringSize();

  BOOST_CHECK(i == 1);
  BOOST_CHECK(j == 2);

  std::string s1 = f->getUnparsedString();
  std::string s2 = f->getUnparsedString();

  BOOST_CHECK(f->getUnparsedStringSize() == 0);

  BOOST_CHECK("this is the second test string" == s1); //these are terrible test cases. They are way too fragile.
  BOOST_CHECK("this is a test string" == s2);
}

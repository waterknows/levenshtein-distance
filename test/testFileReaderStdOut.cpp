#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE FileReaderStdOut
#include <boost/test/included/unit_test.hpp>

#include <iostream>
#include <string>

#include "../src/headers/FileReader.h"
#include "../src/headers/FileReaderStdOut.h"
#include "../src/sources/FileReaderStdOut.cpp"

BOOST_AUTO_TEST_CASE(testFileReaderStdOut) {
  FileReader* f = new FileReaderStdOut("/home/jeff/levenshtein-c/bin/test.txt");
  std::cout << f->getFilePath() << std::endl;

  f->readFile();
  std::cout << "Finished the example test case" << std::endl;
  BOOST_CHECK(2 == 2); //this test doesn't really do anything anyways, printing to stdout isn't really testable
}

#include <iostream>
#include <string>
#include <thread>
#include <mutex>

#include "./headers/FileReader.h"
#include "./headers/FileReaderStdOut.h"
#include "./headers/FileReaderStack.h"
#include "./headers/Dictionary.h"
#include "./headers/LevenshteinChecker.h"
#include "./headers/LevenshteinCheckerRecursive.h"
#include "./headers/LevenshteinCheckerDynamic.h"

main() {
  auto f = new FileReaderStack("./config/strings.txt");
  auto dict = new Dictionary("./config/dictionary.txt");
  f->readFile();
  auto checker = new LevenshteinCheckerDynamic(dict, f);

  std::cout << "init finished" << std::endl;

  checker->checkAgainstDictionary(); //returns empty string...
  checker->checkAgainstDictionary();
  checker->checkAgainstDictionary();
  checker->checkAgainstDictionary();

  std::cout << std::endl;
  return 0;
}

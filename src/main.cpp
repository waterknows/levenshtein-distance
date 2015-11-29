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
  auto f1 = new FileReaderStack("./config/strings.txt");
  auto f2 = new FileReaderStack("./config/strings.txt");
  auto dict = new Dictionary("./config/dictionary.txt");
  f1->readFile();
  f2->readFile();
  auto checkerD = new LevenshteinCheckerDynamic(dict, f1);
  auto checkerR = new LevenshteinCheckerRecursive(dict, f2);

  std::cout << "init finished" << std::endl;

  //remove empty strings
  checkerD->checkAgainstDictionary();
  checkerR->checkAgainstDictionary();


  for (int i = 0; i < f1->getUnparsedStringSize(); i++) {
    checkerD->checkAgainstDictionary();
  }


  std::cout << std::endl;
  return 0;
}

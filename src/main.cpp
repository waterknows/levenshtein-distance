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
#include "./headers/ThreadPool.h"

main() {
  auto f1 = new FileReaderStack("./config/strings.txt");
  auto dict = new Dictionary("./config/dictionary.txt");
  f1->readFile();

  std::cout << "init finished" << std::endl;

  ThreadPool* threadPool = new ThreadPool(f1, dict, "dynamic");

  threadPool->join();

  std::cout << std::endl;
  return 0;
}

#ifndef THREADPOOL_H
#define THREADPOOL_H


#include <thread>
#include <vector>
#include <string>
#include <assert.h>
#include <iostream>

#include "FileReader.h"
#include "LevenshteinChecker.h"
#include "Dictionary.h"
#include "LevenshteinCheckerDynamic.h"
#include "LevenshteinCheckerRecursive.h"

class ThreadPool {

private:
  ThreadPool();
  FileReader* fileReader;
  std::vector<LevenshteinChecker*>* checkers;
  std::vector<std::thread*>* threads;
  void runCheckerInThread(LevenshteinChecker* checker);

public:
  static const int MAX_NUMBER_OF_THREADS = 4;
  ThreadPool(FileReader* fileReader, Dictionary* dictionary, std::string checkerType);
  ~ThreadPool();
  void join(void);


};


#endif

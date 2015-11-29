

#include "../headers/ThreadPool.h"


ThreadPool::ThreadPool(FileReader* fileReader, Dictionary* dictionary, std::string checkerType) {
  this->fileReader = fileReader;
  this->threads = new std::vector<std::thread*>();
  this->checkers = new std::vector<LevenshteinChecker*>();

  LevenshteinChecker* checker;
  std::thread* thread;

  for (int i = 0; i < MAX_NUMBER_OF_THREADS; i++) {
    if (checkerType == "recursive") {
      checker = new LevenshteinCheckerRecursive(dictionary, fileReader);
    }
    else if (checkerType == "dynamic") {
      checker = new LevenshteinCheckerDynamic(dictionary, fileReader);
    }
    else {
      assert (false); //throw an error if the an unknown type is specified
    }

    checkers->push_back(checker);
    thread = new std::thread(&ThreadPool::runCheckerInThread, this, checker);
    threads->push_back(thread);
  }
}

void ThreadPool::runCheckerInThread(LevenshteinChecker* checker) {
  std::cout << "thread started" << '\n';
  while(fileReader->getUnparsedStringSize() > 0) {
    checker->checkAgainstDictionary();
  }
}

void ThreadPool::join(void) {
  for (int i = 0; i < threads->size(); i++) {
    (*threads)[i]->join();
  }
}

ThreadPool::~ThreadPool() {
  delete checkers;
  delete threads;
  delete checkers;
}

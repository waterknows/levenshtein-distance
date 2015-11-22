#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Threading
#include <boost/test/included/unit_test.hpp>

#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>

std::mutex mutex;

void unsafeFunction(int* index) {
  //function that doesn't have a mutex. Creates a race condition so
  //the value of i changes between each run.
  for (int i = 0; i < 10000000; i++) { //if the max value of i is too low this
    //thread will finish before the next on has started
    (*index)++;
  }
}

void safeFunction(int* index) {
  //can either create a lock guard at the start, or a unique lock and lock/unlock it.
  for (int i = 0; i < 10000000; i++) { //if the max value of i is too low this
    //thread will finish before the next on has started
     std::unique_lock<std::mutex> lock1(mutex, std::defer_lock);
     lock1.lock();
     (*index)++;
     lock1.unlock();
  }
}

BOOST_AUTO_TEST_CASE(testDictionary) {
  int* i = new int;
  (*i) = 0;
  int* j = new int;
  (*j) = 0;

  auto ut1 = new std::thread(unsafeFunction, i);
  auto ut2 = new std::thread(unsafeFunction, i);
  auto ut3 = new std::thread(unsafeFunction, i);
  auto ut4 = new std::thread(unsafeFunction, i);
  auto ut5 = new std::thread(unsafeFunction, i);

  auto st1 = new std::thread(safeFunction, j);
  auto st2 = new std::thread(safeFunction, j);
  auto st3 = new std::thread(safeFunction, j);
  auto st4 = new std::thread(safeFunction, j);
  auto st5 = new std::thread(safeFunction, j);

  ut1->join();
  ut2->join();
  ut3->join();
  ut4->join();
  ut5->join();

  st1->join();
  st2->join();
  st3->join();
  st4->join();
  st5->join();

  std::cout << "unsafe: " << (*i) << std::endl;
  std::cout << "safe: " << (*j) << std::endl;
}

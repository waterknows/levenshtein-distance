#include <iostream>

#include <sstream>
#include <string>
#include <fstream>

#include "./headers/FileReader.h"
#include "./headers/FileReaderStdOut.h"
#include "./headers/FileReaderStack.h"

main() {
  FileReaderStack* f = new FileReaderStack("/home/jeff/levenshtein-c/bin/test.txt");
  std::cout << f->getFilePath() << std::endl;

  f->readLine();

  std::stack<std::string>* frstack = f->getStack();

  int i = frstack->size();

  std::string testString = frstack->top();
  frstack->pop();

  int j = frstack->size();

  return 0;
}

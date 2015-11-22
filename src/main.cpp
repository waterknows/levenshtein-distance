#include <iostream>

#include <sstream>
#include <string>
#include <fstream>

#include "./headers/FileReader.h"
#include "./headers/FileReaderStdOut.h"
#include "./headers/FileReaderStack.h"

main() {
  FileReader* f = new FileReaderStdOut("/home/jeff/levenshtein-c/bin/test.txt");
  std::cout << f->getFilePath() << std::endl;

  f->readFile();

  int i = 1/0;

  return 0;
}

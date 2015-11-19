#include <iostream>

#include "./headers/FileReader.h"
#include "./headers/FileReaderStdOut.h"

main() {
  FileReader* f = new FileReaderStdOut("test");
  std::cout << f->getFilePath() << std::endl;

  return 0;
}

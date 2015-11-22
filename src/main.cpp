#include <iostream>

#include <sstream>
#include <string>
#include <fstream>

#include "./headers/FileReader.h"
#include "./headers/FileReaderStdOut.h"
#include "./headers/FileReaderStack.h"
#include "./headers/Dictionary.h"

main() {

  FileReader* f = new FileReaderStack("config/strings.txt");
  Dictionary* dict = new Dictionary("config/dictionary.txt");

  while (f->isFileStillOpen()) {
    f->readLine();
  }

  while (f->getUnparsedStringSize() > 0) {
    std::cout << f->getUnparsedString() << '\n';
  }

  return 0;
}

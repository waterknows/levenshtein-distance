#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>

class FileReader {
  //interface for a file reader object

public:
  virtual ~FileReader() {}
  virtual void readLine(void) = 0; //reads a single line from the file and outputs it to the internal
  virtual void readFile(void) = 0; //reads the whole file by repeatedly reading a single line
  virtual std::string getFilePath(void) = 0; //returns the file path set in the constructor
};

#endif

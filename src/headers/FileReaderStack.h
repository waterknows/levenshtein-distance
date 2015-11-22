#ifndef FILEREADER_STACK_H
#define FILEREADER_STACK_H

#include <string>
#include "FileReader.h"
#include <stack>
#include <fstream>

class FileReaderStack : public FileReader {
private:
  FileReaderStack();
  std::string filepath;
  std::ifstream inputFile;
  std::stack<std::string>* stack;

public:
  FileReaderStack(std::string filepath);
  ~FileReaderStack();
  void readLine(void); //reads a line and prints it to stdout
  void readFile(void); //reads the file line by line and prints it to stdout
  std::string getFilePath(void);

  int getUnparsedStringSize(void);
  bool isFileStillOpen(void);

  std::string getUnparsedString(void);
};



#endif

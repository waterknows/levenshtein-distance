#ifndef FILEREADER_STDOUT_H
#define FILEREADER_STDOUT_H

#include <string>
#include "FileReader.h"
#include <fstream>

class FileReaderStdOut : public FileReader {
private:
  FileReaderStdOut();
  std::string filepath;
  std::ifstream inputFile;

public:
  FileReaderStdOut(std::string filepath);
  ~FileReaderStdOut();
  void readLine(void); //reads a line and prints it to stdout
  void readFile(void); //reads the file line by line and prints it to stdout
  std::string getFilePath(void);

  int getUnparsedStringSize(void);
  bool isFileStillOpen(void);

  std::string getUnparsedString(void);
};

#endif

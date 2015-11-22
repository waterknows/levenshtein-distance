#include "../headers/FileReaderStdOut.h"
#include <iostream>

FileReaderStdOut::FileReaderStdOut(std::string filepath) {
  this->filepath = filepath;
  inputFile.open(filepath);
}

std::string FileReaderStdOut::getFilePath() {
  return filepath;
}

void FileReaderStdOut::readLine() {
  std::string line;
  if (!std::getline(inputFile, line)) {
    inputFile.close();
  }
  std::cout << line << "\n";
}

void FileReaderStdOut::readFile() {
  while (inputFile) {
    readLine();
  }
}

int FileReaderStdOut::getUnparsedStringSize(void) {
  return 0; //there are never unparsed strings since they go to stdout
}

bool FileReaderStdOut::isFileStillOpen(void) {
  return inputFile.is_open();
}

std::string FileReaderStdOut::getUnparsedString(void) {
  return "";
}

FileReaderStdOut::~FileReaderStdOut() {
  if (inputFile.is_open()) {
    inputFile.close();
  }
}

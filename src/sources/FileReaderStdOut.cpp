#include "../headers/FileReaderStdOut.h"
#include <fstream>
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
  std::getline(inputFile, line);
  std::cout << line << "\n";
}

void FileReaderStdOut::readFile() {
  while (inputFile) {
    readLine();
  }
}

FileReaderStdOut::~FileReaderStdOut() {
  inputFile.close();
}

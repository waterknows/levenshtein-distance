#include "../headers/FileReaderStack.h"
#include <fstream>
#include <iostream>
#include <stack>

FileReaderStack::FileReaderStack(std::string filepath) {
  this->filepath = filepath;
  inputFile.open(filepath);
}

std::string FileReaderStack::getFilePath() {
  return filepath;
}

void FileReaderStack::readLine() {
  std::string line;
  std::getline(inputFile, line);
  stack.push(std::string(line));
}

void FileReaderStack::readFile() {
  while (inputFile) {
    readLine();
  }
}

FileReaderStack::~FileReaderStack() {
  inputFile.close();
}

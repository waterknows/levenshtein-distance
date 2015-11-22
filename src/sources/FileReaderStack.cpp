#include "../headers/FileReaderStack.h"

FileReaderStack::FileReaderStack(std::string filepath) {
  this->filepath = filepath;
  inputFile.open(filepath);
  this->stack = new std::stack<std::string>();
}

std::string FileReaderStack::getFilePath() {
  return filepath;
}

void FileReaderStack::readLine() {
  std::string line;
  if (!std::getline(inputFile, line)) {
    inputFile.close();
  }
  stack->push(std::string(line));
}

void FileReaderStack::readFile() {
  while (inputFile) {
    readLine();
  }
}

int FileReaderStack::getUnparsedStringSize(void) {
  return stack->size();
}

bool FileReaderStack::isFileStillOpen(void) {
  return inputFile.is_open();
}

std::string FileReaderStack::getUnparsedString(void) {
  std::string out;
  out = stack->top();
  stack->pop();
  return out;
}

FileReaderStack::~FileReaderStack() {
  if (inputFile.is_open()) {
    inputFile.close();
  }
  delete stack;
}

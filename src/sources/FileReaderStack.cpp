#include "../headers/FileReaderStack.h"
#include <fstream>
#include <iostream>
#include <stack>

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
  std::getline(inputFile, line);
  stack->push(std::string(line));
}

void FileReaderStack::readFile() {
  while (inputFile) {
    readLine();
  }
}

std::stack<std::string>* FileReaderStack::getStack() {
  return stack;
}

FileReaderStack::~FileReaderStack() {
  inputFile.close();
}

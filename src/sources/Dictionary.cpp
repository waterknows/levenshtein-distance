#include "../headers/Dictionary.h"


Dictionary::Dictionary(std::string filepath) {
  this->filepath = filepath;
  inputFile.open(filepath);
  this->wordsInDictionary = new std::vector<std::string>();
  readFile();
}

Dictionary::~Dictionary() {
  if (inputFile.is_open()) {
    inputFile.close();
  }
  delete wordsInDictionary;
}

void Dictionary::readFile(void) {
  std::string line;
  while (std::getline(inputFile, line)) {
    wordsInDictionary->push_back(std::string(line));
  }
  inputFile.close();
}
std::string Dictionary::getFilePath(void) {
  return filepath;
}

int Dictionary::getSize(void) {
  return wordsInDictionary->size();
}

std::string Dictionary::getWord(int index) {
  return (*wordsInDictionary)[index];
}

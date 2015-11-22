#ifndef DICTIONARY_H
#define DICTIONARY_H


#include <string>
#include <vector>
#include <fstream>


class Dictionary {
private:
  Dictionary();
  std::string filepath;
  std::ifstream inputFile;
  std::vector<std::string>* wordsInDictionary;
  void readFile(void); //called in constructor

public:
  Dictionary(std::string filepath);
  ~Dictionary();

  std::string getFilePath(void);

  int getSize(void);

  std::string getWord(int index);

};


#endif

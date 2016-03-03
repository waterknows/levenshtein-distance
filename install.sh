#!/bin/bash

# install requirements
sudo apt-get install build-essential -y
sudo apt-get install libboost-all-dev -y

# create folder structure
mkdir bin
mkdir bin/tests


# create dictionary file to check the words against
cat /usr/share/dict/words > config/dictionary.txt

# copy over the test file to the test directory
cp test/test.txt bin/tests

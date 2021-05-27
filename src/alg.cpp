// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> Tree;
  char prop;
  std::string str;
  std::ifstream file(filename);
       if (!file) {
       std::cout << "File error!" << std::endl;
       return Tree;
       }
       while (!file.eof()) {
       prop = file.get();
         if ((prop >= 'A' && prop <= 'Z') || (prop >= 'a' && prop <= 'z')) {
           if (prop >= 'A' && prop <= 'Z') {
               prop += ('a'-'A');
           }
       str += prop;
         } else if (str != "") {
           Tree.add(str);
           str = "";
         }
        }
        file.close();
        return Tree;
}

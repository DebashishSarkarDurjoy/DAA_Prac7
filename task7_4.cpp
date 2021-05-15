#include <iostream>
#include <map>
#include <fstream>

using namespace std;

#include "AVL_ADT.h"


char asciitolower(char in) {
    if (in <= 'Z' && in >= 'A')
        return in - ('Z' - 'z');
    return in;
}

int main() {

  string x;
  ifstream inFile;
  

  map<string, int> dataBook;
  pair<string, int> p;

  inFile.open("test.txt");
  if (!inFile) {
      cout << "Unable to open file";
      exit(1); // terminate with error
  }

  while (inFile >> x) {
    //https://stackoverflow.com/questions/313970/how-to-convert-stdstring-to-lower-case/24063783
    // -----------Trimming----------------
    transform(x.begin(), x.end(), x.begin(), [](unsigned char c){ return tolower(c); });

    for (int i = 0, len = x.size(); i < len; i++)
    {
        if (ispunct(x[i]))
        {
            x.erase(i--, 1);
            len = x.size();
        }
    }
    // -----------end Trimming------------


    bool isPresent = false;
    for (auto it=dataBook.begin(); it!=dataBook.end(); it++) {
      if (it->first == x) {
        it->second++;
        if (!isPresent) isPresent = true;
      }
    }
    if (!isPresent) {
      p.first = x;
      p.second = 1;
      dataBook.insert(p);
    }

  }

  cout << "Map: " << endl;
  for (auto it=dataBook.begin(); it!=dataBook.end(); it++) {
    cout << it->first << "->" << it->second << endl;

  }



  inFile.close();

  return 0;
}

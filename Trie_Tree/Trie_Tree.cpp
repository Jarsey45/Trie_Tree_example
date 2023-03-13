#include <iostream>
#include <string>
#include <fstream>
#include "trie_tree.h"

using std::cout;
using std::cin;

string* loadFile() {
    string* words = new string[10000];

    //loading file
    std::ifstream wordFile;
    wordFile.open("google-10000-english.txt");

    if (wordFile.is_open()){
        for (int i = 0; i < 10000; i++) {
            if (wordFile.eof()) break;
            std::getline(wordFile, words[i]);
        }
        wordFile.close();
    }

    return words;
}

int main()
{
    //slowa do wprowadzenia do 'bazy danych' TRIE
    string* words = loadFile();
    int n = 10000;
    
    Trie_Tree tree;

    // wprowadzam slowa do trie
    for (int i = 0; i < n; i++)
        tree.insertWord(words[i]);


    // wyszukiwanie czy slowa istnieja
    string slowo;
    cout << "Wpisz swoje slowo: \n";
    while(slowo !=  "koniec") {
        cout << "Twoje slowo: ";
        cin >> slowo;
        if (tree.search(slowo))
            cout << "       Slowo " << slowo << " -> istnieje.\n";
        else
            cout << "       Slowo: " << slowo << " -> nie istnieje.\n";
    }


    delete [] words;
    return 0;
}

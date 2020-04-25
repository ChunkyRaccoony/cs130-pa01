#ifndef HASHPROGRAM_H
#define HASHPROGRAM_H

#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

class HashProgram {
    public: 
        HashProgram(){
            curr_size = 0;
        }

        size_t insertHash(string word);
        void deleteHash(string word);
        void searchHash(string word);
        void rangeSearch(string word1, string word2);


    private:
        int curr_size;
        const static size_t TABLESIZE = 10000;
        const static size_t PRIME = 9973;
        pair<string,size_t> table[TABLESIZE];
        size_t hash1(string& word);
        size_t hash2(string& word);

};

#endif
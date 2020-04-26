// HashProgram.cpp

#include "HashProgram.h"
#include <algorithm> 

using namespace std;

// size_t HashProgram::hash1(string& word){h h
//     return ((word[0]+word[word.length()-1]-97*2) % TABLESIZE);
// }
// size_t HashProgram::hash2(string& word){
//     return (PRIME - ((word[0]+word[word.length()-1]-97*2) % PRIME));
// }
size_t HashProgram::hash(string word) const {
    size_t accumulator = 0;
    for (size_t i=0; i<word.size(); i++){
        accumulator += (word.at(i)-97);
    }
    return accumulator % TABLESIZE;
}
size_t HashProgram::insertHash(string word){
    int index = hash(word);
    int k = 0;
    for(int i=0; i < table[index].size(); i++){
        if ((table[index][i].first).compare(word) == 0){
            table[index][i].second += 1;
            return (table[index][i].second);
        }
        if ((table[index][i].first == "" && table[index][i].second == -1)){
            table[index][i].first = word;
            table[index][i].second = 1;
            return (table[index][i].second);
        }
    }
            table[index].push_back(make_pair(word,1)); 
            return(table[index][table[index].size()-1].second);
}

size_t HashProgram::searchHash(string word){
    // int index1 = hash1(word);
    // int index2 = hash2(word);
    int index = hash(word);
    for (int i = 0; i< table[index].size(); i++){
        if (table[index][i].first == word){
            cout << word <<" found, count = "<<(table[index][i].second)<<endl;
            return (table[index][i].second);
        }
    }
    cout << word  << " not found" <<endl;
    return(0);
}

int HashProgram::deleteHash(string word){
    int index = hash(word);
    for (int i = 0; i < table[index].size(); i++){
        if(table[index][i].first == word){
            if(table[index][i].second > 1){
                table[index][i].second -= 1;
                cout<<word<<" deleted, new count = "<<(table[index][i].second)<<endl;
                return (table[index][i].second);
            }
            if(table[index][i].second == 1){
                table[index][i].first = "";
                table[index][i].second = -1;
                cout<<word<<" deleted"<<endl;
                return (table[index][i].second);
            }
        }
    }
    return (0);
}

void HashProgram::rangeSearch(string word1, string word2){
    string max;
    string min;
    if ((word1.compare(word2)) >= 0) {
        max = word1;
        min = word2;
    }else{
        max = word2;
        min = word1;
    }
    // cout<<"range search "<<min <<" to "<<max<<endl;
    vector<string> rangeTable;
    for(int i = 0; i < TABLESIZE; i++){
        for(int j = 0; j < table[i].size(); j++){
        if((table[i][j].first).compare(min) >= 0 && (table[i][j].first).compare(max) <= 0){
            rangeTable.push_back(table[i][j].first);
        }
        }
    }
    sort(rangeTable.begin(),rangeTable.end());
    for(int i = 0; i < rangeTable.size(); i++){
            cout << rangeTable[i]<<endl;
        }
}
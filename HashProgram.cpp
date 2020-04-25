// HashProgram.cpp

#include "HashProgram.h"
#include <algorithm> 

using namespace std;

size_t HashProgram::hash1(string& word){
    return ((word[0]+word[word.length()-1]-97*2) % TABLESIZE);
}
size_t HashProgram::hash2(string& word){
    return (PRIME - ((word[0]+word[word.length()-1]-97*2) % PRIME));
}
size_t HashProgram::insertHash(string word){
    int index = hash1(word);
    if(table[index].second != 0) {
        if (table[index].first == word){
            table[index].second += 1;
            // cout<<"this existed before"<<endl;
            cout<< word << " inserted, new count = " <<  (table[index].second) <<endl;
            return (index);
        }
        int index2 = hash2(word);
        int i = 1;
        while(true) {
            int goodIndex = (index + i * index2) % TABLESIZE;
            if (table[goodIndex].first == word){
                table[goodIndex].second += 1;
                // cout<<"existed with occupied previously"<<endl;
                cout<< word << "inserted, new count = " <<  (table[goodIndex].second) <<endl;
                return (goodIndex);
            } 
            if(table[goodIndex].second == 0) {
                table[goodIndex].first = word;
                table[goodIndex].second += 1;
                // cout<<"new stuff with occupied previously "<<endl;
               cout<< word << " inserted, new count = " <<  (table[goodIndex].second) <<endl;
               curr_size++; 
               return (goodIndex);
            }
            i++;
        }
    }else{
        table[index].first = word;
        table[index].second += 1;
        // cout<<"new stuff"<<endl;
        cout<< word << " inserted, new count = " <<  (table[index].second) <<endl;
        curr_size++;
        return (index);
    }
}

void HashProgram::searchHash(string word){
    int index1 = hash1(word);
    int index2 = hash2(word);
    int i = 0;
    while ((table[(index1 + i * index2) % TABLESIZE].first != "") && (i < 10000)){
        if ((table[(index1 + i * index2) % TABLESIZE].first) == word){
            cout << word <<" found, count = "<< (table[(index1 + i * index2) % TABLESIZE].second)<<endl;
    }
    i++;
    }
    cout << word  << " not found" <<endl;
}

void HashProgram::deleteHash(string word){
    int index1 = hash1(word);
    int index2 = hash2(word);
    int i = 0;
    while ((table[(index1 + i * index2) % TABLESIZE].first != "") && (i < 10000)){
        if (table[(index1 + i * index2) % TABLESIZE].first == word){
            if (table[(index1 + i * index2) % TABLESIZE].second == 1){
                table[(index1 + i * index2) % TABLESIZE].first = "";
                table[(index1 + i * index2) % TABLESIZE].second = 0;
                curr_size -= 1;
                cout<< word << " deleted"<<endl;
            }else{
                table[(index1 + i * index2) % TABLESIZE].second -= 1;
                cout<< word << " deleted, new count = "<<(table[(index1 + i * index2) % TABLESIZE].second)<<endl;
            }
        }
        i+=1;
    }    
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
        if((table[i].first).compare(min) >= 0 && (table[i].first).compare(max) <= 0){
            rangeTable.push_back(table[i].first);
        }
        sort(rangeTable.begin(),rangeTable.end());
    }
    for(int i = 0; i < rangeTable.size(); i++){
            cout << rangeTable[i]<<endl;
        }
}
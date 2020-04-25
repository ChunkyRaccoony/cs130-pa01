#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include "HashProgram.h"
#include "BstTree.h"
using namespace std;

int main(int argc, char* argv[]){
    if (argc < 2) {
        cerr << "Error: " << argv[0] << " Please enter a input word" << endl;
        return 1;
    }
    HashProgram a;
    BstTree b;
    string info = argv[1]; 
    // stringstream ss(info); 
    string delimiter = ", ";
    vector <string> substring; 
    size_t pos = 0;
    string token;
    while ((pos = info.find(delimiter)) != string::npos) {
    token = info.substr(0, pos);
    substring.push_back(token);
    info.erase(0, pos + delimiter.length());
    }
    substring.push_back(info);
    for (size_t i = 0; i < substring.size(); i++){
        string subinfo = substring[i];
        vector <string> subwords;
        pos = 0;
        string delimiter2 = " ";
        while ((pos = subinfo.find(delimiter2)) != string::npos) {
                token = subinfo.substr(0, pos);
                subwords.push_back(token);
                subinfo.erase(0, pos + delimiter2.length());
        }
        subwords.push_back(subinfo);

        if(subwords[0] == "search"){
            a.searchHash(subwords[1]);
            b.bstSearch(subwords[1]);
        }else if (subwords[0] == "insert"){
            a.insertHash(subwords[1]);
            b.bstInsert(subwords[1]);
        }else if (subwords[0] == "delete"){
            a.deleteHash(subwords[1]);
            b.bstDelete(subwords[1]);
        }else if (subwords[0] == "range"){
            a.rangeSearch(subwords[2],subwords[4]);
            b.bstRangeSearch(subwords[2],subwords[4]);
        }
        }
        

    } 


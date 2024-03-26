#include <iostream>
#include <sstream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main(){
    string words, temp;
    getline(cin, words);
    stringstream ss(words);
    unordered_map<char, unordered_set<string>> dict;
    while(ss>>temp){
        dict[temp[0]].insert(temp);
    }
    getline(cin, words);
    stringstream s2(words);
    while(s2>>temp){
        if(!dict.count(temp[0])) cout << temp << " ";
        else {
            string minStr = temp;
            for(auto it:dict[temp[0]]){
                if(it.length()<temp.length() && it.length() < minStr.length()){
                    if(temp.starts_with(it)) minStr = it;
                }
            }
            cout << minStr << " ";
        }
    }
    return 0;
}
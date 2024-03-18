#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    string s;
    unordered_map<char,int> letters;
    cin >> s;
    for(int i=0;i<s.length();i++){
        letters[s[i]]++;
    }
    cin >> s;
    for(int i=0;i<s.length();i++){
        letters[s[i]]--;
    }
    for(auto it:letters){
        if(it.second!=0){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
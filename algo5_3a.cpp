#include <iostream>
#include <sstream>
#include <unordered_map>
#include <set>

using namespace std;

int main(){
    int n, temp;
    string s, song;
    cin >> n;
    unordered_map<string,int> songs;
    for(int i=0;i<n;i++){
        cin >> temp;
        for(int j=0;j<temp;j++){
            cin >> s;
            songs[s]++;
        }
    }
    int counter = 0;
    set<string> ans;
    for(auto it:songs){
        if(it.second == n) {
            ans.insert(it.first);
            counter++;
        }
    }
    cout << counter <<"\n";
    if(counter > 0) {
        for(auto it:ans){
            cout << it << " ";
        }
    }
    return 0;
}
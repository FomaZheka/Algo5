#include <iostream>
#include <unordered_set>
#include <set>

using namespace std;

void readNums(unordered_set<int>& s){
    int n, temp;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> temp;
        s.insert(temp);
    }
}

int main(){
    int n, temp;
    unordered_set<int> s1,s2,s3;
    set<int> ans;
    readNums(s1);
    readNums(s2);
    readNums(s3);
    for(auto it:s1){
        if(s2.count(it) || s3.count(it)) ans.insert(it);
    }
    for(auto it:s2){
        if(s3.count(it)) ans.insert(it);
    }
    for(auto it:ans){
        cout << it <<" ";
    }
    return 0;
}
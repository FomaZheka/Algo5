#include <iostream>
#include <vector>

using namespace std;

int checkPos(vector<vector<int>>& deck,int posI, int posJ, int& ans){
    if(posI<0 || posI>7 || posJ<0 || posJ>7) return -1;
    if(deck[posI][posJ]==-1) return -1;
    else if(deck[posI][posJ]==0){
        deck[posI][posJ] = 1;
        ans--;
    }
    return 0;
}

int main()
{
    vector<vector<int>> deck(8,vector<int> (8,0));
    int ans = 64;
    vector<vector<int>> r;
    vector<vector<int>> b;
    string str;
    for(int i=0;i<8;i++){
        cin >> str;
        for(int j=0;j<8;j++){
            if(str[j] == 'B') {
                b.push_back({i,j});
                deck[i][j]=-1;
                ans--;
            }
            else if(str[j] == 'R') {
                r.push_back({i,j});
                deck[i][j]=-1;
                ans--;
            }
        }
    }
    for(auto it:r){
        int Ri = it[0];
        int Rj = it[1];
        for(int i=Ri-1;i>=0;i--){
            int a = checkPos(deck,i,Rj,ans);
            if(a==-1) break;
        }
        for(int i=Ri+1;i<8;i++){
            int a = checkPos(deck,i,Rj,ans);
            if(a==-1) break;
        }
        for(int j=Rj-1;j>=0;j--){
            int a = checkPos(deck,Ri,j,ans);
            if(a==-1) break;
        }
        for(int j=Rj+1;j<8;j++){
            int a = checkPos(deck,Ri,j,ans);
            if(a==-1) break;
        }
    }
    for(auto it:b){
        int Bi = it[0];
        int Bj = it[1];
        for(int i=1;i<8;i++){
            int a = checkPos(deck,Bi-i,Bj-i,ans);
            if(a==-1) break;
        }
        for(int i=1;i<8;i++){
            int a = checkPos(deck,Bi+i,Bj-i,ans);
            if(a==-1) break;
        }
        for(int i=1;i<8;i++){
            int a = checkPos(deck,Bi+i,Bj+i,ans);
            if(a==-1) break;
        }
        for(int i=1;i<8;i++){
            int a = checkPos(deck,Bi-i,Bj+i,ans);
            if(a==-1) break;
        }
    }
    cout << ans;
    return 0;
}
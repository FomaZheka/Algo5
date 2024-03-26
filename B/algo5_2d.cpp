#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main(){
    int n, tempX, tempY;
    unordered_map<int,unordered_set<int>> board;
    cin >> n;
    int ans;
    for(int i=0;i<n;i++){
        cin >> tempX >> tempY;
        board[tempX].insert(tempY);
        ans+=4;
        if(board[tempX-1].count(tempY)) ans-=2;
        if(board[tempX+1].count(tempY)) ans-=2;
        if(board[tempX].count(tempY+1)) ans-=2;
        if(board[tempX].count(tempY-1)) ans-=2;
    }
    cout << ans;
    return 0;
}

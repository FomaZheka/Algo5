#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

int main(){
    int n, r, c;
    cin >> n;
    vector<int> dist(n+1,0);
    vector<bool> row(n+1, true);
    unordered_map<int, vector<int>> dataByCol;
    map<int, vector<int>> dataByRow;
    for(int i=0;i<n;i++){
        cin >> r >> c;
        dataByCol[c].push_back(r);
        dataByRow[r].push_back(c); 
        int left = c-1;
        int right = c+1;
        int d = 1;
        while(left>=0 || right<=n){
            if(left>=0) dist[left--]+=d;
            if(right<=n) dist[right++]+=d;
            d++;
        }
    }
    int maxVal = dist[1];
    int maxCol = 1;
    for(int i=1;i<=n;i++){
        if(dist[i]<maxVal){
            maxVal = dist[i];
            maxCol = i;
        }
    }
    int ans = dist[maxCol];
    int freeCol = 1;
    for(int i:dataByCol[maxCol]) row[i] = false;
    for(auto it:dataByRow){
        //if(it.first == maxCol) continue;
        for(int i:it.second){
            if(i == maxCol) continue;
            if(row[it.first]){
                row[it.first] = false;
            } else {
                while(!row[freeCol]){
                    freeCol++;
                }
                row[freeCol] = false;
                int add = abs(freeCol - it.first);
                ans+=add;
            }
        }
    }
    cout << ans;
    return 0;
}
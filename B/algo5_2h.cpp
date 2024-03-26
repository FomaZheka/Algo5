#include <iostream>
#include <vector>

using namespace std;

int solve(vector<vector<int>>& data, int exRow, int exCol){
    int maxEl = 0;
    for(int i=0;i<data.size();i++){
        if(i==exRow) continue;
        for(int j=0;j<data[i].size();j++){
            if(j == exCol) continue;
            if(data[i][j]>maxEl){
                maxEl = data[i][j];
            }
        }
    }
    return maxEl;
}


int main(){
    int row, col, temp;
    cin >> row >> col;
    int maxRow = 0;
    int maxCol = 0;
    int maxPower = 0;
    vector<vector<int>> data(row, vector<int>(col,0));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin >> temp;
            data[i][j] = temp;
            if(temp>maxPower){
                maxRow = i;
                maxCol = j;
                maxPower = temp;
            }
        }
    }
    int minPower = maxPower;
    int minRow = maxRow;
    int minCol = maxCol;
    for(int i=0;i<col;i++){
        int tempMin = solve(data,maxRow,i);
        if(tempMin < minPower){
            minPower = tempMin;
            minRow = maxRow;
            minCol = i;
        }
    }
    for(int i=0;i<row;i++){
        int tempMin = solve(data,i,maxCol);
        if(tempMin < minPower){
            minPower = tempMin;
            minRow = i;
            minCol = maxCol;
        }
    }
    cout << minRow + 1<< " " << minCol + 1;
    return 0;
}
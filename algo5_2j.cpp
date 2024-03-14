#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> dRow = {-1, 1, 0, 0};
vector<int> dCol = {0, 0, -1, 1};

struct pair_hash {
    inline size_t operator()(const pair<int,int> & v) const {
        return v.first*42 + v.second;
    }
};

//Find MinRow, MaxRow, MinCol, MaxCol
void findBoards(unordered_set<pair<int,int>,pair_hash>& rect, int& minRow, int& minCol, int& maxRow, int& maxCol){
    int minRow = 1000;
    int maxRow = -1;
    int minCol = 1000;
    int maxCol = -1;
    for(auto it:rect){
        maxRow = max(it.first,maxRow);
        maxCol = max(it.second,maxCol);
        minRow = min(it.first,minRow);
        minCol = min(it.second,minCol);
    }
}

//Проверка на прямоугольность
bool isRect(unordered_set<pair<int,int>,pair_hash>& rect){
    if(rect.empty())return false;
    int minRow, maxRow, minCol, maxCol;
    findBoards(rect, minRow, minCol, maxRow, maxCol);
    return (maxRow-minRow+1)*(maxCol-minCol+1) == rect.size(); 
}

//Деление прямоугольника на два
void splitRect(vector<vector<char>>& paint, unordered_set<pair<int,int>,pair_hash>& rect){
    if(rect.empty()) return;
    int minRow, maxRow, minCol, maxCol;
    findBoards(rect, minRow, minCol, maxRow, maxCol);
    if(maxCol == minCol || maxRow == minRow){
        paint[maxRow][maxCol] = 'b';
        return;
    }
    for(auto it:rect){
        if(it.first == maxRow) paint[it.first][it.second] = 'b';
    }
}

//Деление фигуры на 2 прямоугольника
bool splitIntoTwoRect(vector<vector<char>>& paint, unordered_set<pair<int,int>,pair_hash>& rect){
    unordered_set<pair<int,int>,pair_hash> toCheck;
    unordered_set<pair<int,int>,pair_hash> temp = rect;
    int minRow, maxRow, minCol, maxCol;
    findBoards(rect, minRow, minCol, maxRow, maxCol);

    for(int row = minRow; row<maxRow;row++){
        for(int col = minCol;col<=maxCol;col++){
            if(rect.count({row,col})) {
                toCheck.insert({row,col});
                temp.erase({row,col});
            }
        }
        if(isRect(toCheck) && isRect(temp)){
            isRect(temp);
            for(auto it:toCheck){
                paint[it.first][it.second] = 'b';
            }
            return true;
        }
    }
    temp = rect;
    toCheck = {};
    for(int col = minCol; col<maxCol;col++){
        for(int row = minRow;row<=maxRow;row++){
            if(rect.count({row,col})) {
                toCheck.insert({row,col});
                temp.erase({row,col});
            }
        }
        if(isRect(toCheck) && isRect(temp)){
            for(auto it:toCheck){
                paint[it.first][it.second] = 'b';
            }
            return true;
        }
    }
    return false;
}

//Создание фигуры из найденной точки
unordered_set<pair<int,int>, pair_hash> makeRect(vector<vector<char>>& paint, int startRow, int startCol, char ch){
    queue<pair<int,int>> q;
    unordered_set<pair<int,int>, pair_hash> ans = {{startRow,startCol}};
    q.push({startRow,startCol});
    paint[startRow][startCol] = ch;
    while(!q.empty()){
        for(int i=0;i<dRow.size();i++){
            if(paint[q.front().first + dRow[i]][q.front().second + dCol[i]] == '#'){
                q.push({q.front().first + dRow[i],q.front().second + dCol[i]});
                ans.insert({q.front().first + dRow[i],q.front().second + dCol[i]});
                paint[q.front().first + dRow[i]][q.front().second + dCol[i]] = ch;
            }
        }
        q.pop();
    }
    return ans;
}

//Нахождение #
bool findNextRect(vector<vector<char>>& paint, int& startRow, int& startCol){
    for(int i=1;i<paint.size()-1;i++){
        for(int j=1;j<paint[i].size()-1;j++){
            if(paint[i][j]=='#'){
                startRow = i;
                startCol = j;
                return true;
            }
        }
    }
    return false;
}


int main(){
    int row, col;
    cin >> row >> col;
    vector<vector<char>> paint(row+2, vector<char>(col+2,'b'));
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            cin >> paint[i][j];
        }
    }
    //найти первый прямоугольник
    int startRow, startCol;
    if(!findNextRect(paint,startRow,startCol)){
        cout << "NO";
        return 0;
    }
    //найти второй прямоугольник
    unordered_set<pair<int,int>, pair_hash> rect = makeRect(paint,startRow,startCol,'a');
    if(!findNextRect(paint,startRow,startCol)){
        //Если один и он прямоугольник
        if(isRect(rect)){
            if(rect.size()>1)splitRect(paint,rect);
            else {
                cout << "NO";
                return 0;
            }
        } else {
            //Если один и он не прямоугольник
            if(!splitIntoTwoRect(paint,rect)){
                cout << "NO";
                return 0;
            }
        }
    } else {
        unordered_set<pair<int,int>,pair_hash> secondRect = makeRect(paint,startRow,startCol,'b');
        //Если их больше 2
        if(findNextRect(paint,startRow,startCol)){
            cout << "NO";
            return 0;
        }
        //Если их два
        if(!isRect(rect) || !isRect(secondRect)){
            cout << "NO";
            return 0;
        }

    }
    //Print
    cout << "YES\n";
    for(int i=1;i<paint.size()-1;i++){
        for(int j=1;j<paint[i].size()-1;j++){
            cout << paint[i][j];
        }
        cout<<"\n";
    }


    return 0;
}
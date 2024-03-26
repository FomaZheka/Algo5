#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <math.h>


using namespace std;

struct Match{
    Match(){x=0;y=0;dirX=0;dirY=0;}
    Match(long long xx, long long yy, long long xx2, long long yy2):x(xx), y(yy), dirX(xx2 - xx), dirY(yy2 - yy) {}

    bool operator== (const Match& b) const{
        return x==b.x && dirX==b.dirX && y==b.y && b.dirY==dirY;
    }

    long long x;
    long long y;
    long long dirX;
    long long dirY;
};

struct hashMatch{
    size_t operator() (const Match& m) const{
        return m.x * 42 * 42 * 42 + m.dirX * 42 * 42  + m.dirY * 42 + m.y;
    }
};

struct hashMapMatch{
    size_t operator() (const pair<long long,long long>& p) const{
        return p.first*127543 + p.second*629;
    }
};

unordered_map<long long, unordered_set<Match,hashMatch>> readImage(long long n){
    unordered_map<long long, unordered_set<Match,hashMatch>> ans;
    long long x1, y1, x2, y2;
    for(long long i=0;i<n;i++){
        cin >> x1 >> y1 >> x2 >> y2;
        if(y1 < y2 || (y1==y2 && x1<x2)){
            long long temp = x1;
            x1 = x2;
            x2 = temp;
            temp = y1;
            y1 = y2;
            y2 = temp;
        }
        long long hash = (x2 - x1) * 42 * 42 + (y2 - y1) * 42;
        ans[hash].insert({x1,y1,x2,y2});
    }
    return ans;
}

int main(){
    long long n;
    cin >> n;
    unordered_map<long long, unordered_set<Match,hashMatch>> imageA = readImage(n);
    unordered_map<long long, unordered_set<Match,hashMatch>> imageB = readImage(n);
    long long maxRes = 0;
    unordered_map<pair<long long,long long>,long long,hashMapMatch> res;
    for(auto it:imageB){
        
        if(imageA.count(it.first)){
            for(auto itB:it.second){
                for(auto itA:imageA[it.first]){
                    long long diffX = itA.x - itB.x;
                    long long diffY = itA.y - itB.y;
                    res[{diffX,diffY}]++;
                }
            }
        }
    }
    for(auto it:res){
        maxRes = max(maxRes,it.second);
    }
    cout << n - maxRes;
    return 0;
}
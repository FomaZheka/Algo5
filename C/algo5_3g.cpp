#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <math.h>

using namespace std;

struct Point{
    Point(){x=0;y=0;}
    Point(int xx, int yy):x(xx),y(yy){}
    int x;
    int y;

    bool operator== (const Point& p) const{
        return x == p.x && y == p.y;
    }
};

struct hashPoint{
    size_t operator() (const Point& p) const{
        return p.x * 42 * 42 + p.y * 42;
    }
};

void calc(unordered_set<Point,hashPoint>& points, Point& prevPoint, Point& nextPoint, vector<Point>& ans, int diffX, int diffY){
    vector<Point> vTemp;
    Point temp1 = {prevPoint.x + diffY,prevPoint.y + diffX};
    Point temp2 = {nextPoint.x + diffY,nextPoint.y + diffX};
    if(!points.count(temp1)) vTemp.push_back(temp1);
    if(!points.count(temp2)) vTemp.push_back(temp2);
    if(vTemp.size() < ans.size()) ans = vTemp;
}

void findRect(unordered_set<Point,hashPoint>& points, Point& prevPoint, Point& nextPoint, vector<Point>& ans){
    int diffX = prevPoint.x-nextPoint.x;
    int diffY = prevPoint.y-nextPoint.y;
    calc(points,prevPoint,nextPoint,ans,diffX,-diffY);
    calc(points,prevPoint,nextPoint,ans,-diffX,diffY);
}


int main(){
    int n, tX, tY;
    cin >> n;
    unordered_set<Point,hashPoint> points;
    vector<Point> ans(5);
    if(n==1){
        cin >> tX >> tY;
        ans = {{tX+1,tY+1},{tX+1,tY},{tX,tY+1}};
    } else {
        for(int i=0;i<n;i++){
            cin >> tX >> tY;
            Point nextPoint(tX,tY);
            for(auto it: points){
                findRect(points, it,nextPoint,ans);
                if(ans.empty()) break;
            }
            if(ans.empty()) break;
            points.insert(nextPoint);
        }
    }
    cout << ans.size();
    for(int i=0;i<ans.size();i++){
        cout << "\n" << ans[i].x << " " << ans[i].y;
    }
    return 0;
}
#include <iostream>
#include <climits>

using namespace std;

int main(){
    int k, tempX, tempY;
    cin >> k;
    int minX = INT_MAX;
    int minY = INT_MAX;
    int maxX = INT_MIN;
    int maxY = INT_MIN;
    for(int i=0;i<k;i++){
        cin >> tempX >> tempY;
        minX = min(tempX,minX);
        minY = min(tempY, minY);
        maxX = max(tempX,maxX);
        maxY = max(tempY,maxY);
    }
    cout << minX << " " << minY << " " << maxX << " " << maxY << " "; 
    return 0;
}

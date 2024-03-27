#include <iostream>
#include <vector>

using namespace std;


int separate(const vector<int>& words, const int len){
    int rows = 1;
    int cur = 0;
    for(int i=0;i<words.size();i++){
        if(cur>0) cur++;
        cur +=words[i];
        if(cur>len){
            cur = words[i];
            rows++;
        }
    }
    return rows;
}

int solve(const vector<int>& leftPart, int minLeft, const vector<int>& rightPart, int minRight, int len){
    int left = minLeft;
    int right = len - minRight;
    int minRow = len;
    while(left <= right){
        int mid = left + (right-left+1)/2;
        int rowLeft = separate(leftPart,mid);
        int rowright = separate(rightPart,len - mid);
        minRow = min(minRow,max(rowLeft,rowright));
        if(left==right) {
             break;
        }
        if(rowLeft > rowright){
            left = mid;
        } else {
            right = mid - 1;
        } 
        
    }
    return minRow;
}

int main(){
    int len, n, m;
    cin >> len >> n >> m;
    vector<int> left(n);
    vector<int> right(m);
    int minLeft = 0;
    int minRight = 0;
    for(int i=0;i<n;i++){
        cin >> left[i];
        minLeft = max(minLeft,left[i]);
    }
    for(int i=0;i<m;i++){
        cin >> right[i];
        minRight = max(minRight,right[i]);
    }

    cout << solve(left,minLeft,right,minRight,len);

}
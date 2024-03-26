#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, temp;
    int sum = 0;
    int maxNum = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> temp;
        sum+=temp;
        maxNum = max(maxNum,temp);
    }
    if(sum - maxNum < maxNum) cout << maxNum - (sum-maxNum);
    else cout << sum;
    return 0;
}

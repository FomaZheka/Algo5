#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, temp, a, b, k;
    cin >> n;
    vector<int> nums(n+1);
    for(int i=0;i<n;i++){
        cin >> temp;
        nums[i] = temp;
    }
    nums[n] = nums[0];
    int maxNum = 0;
    cin >> a >> b >> k;
    int counter = 0;
    for(int i=a;i<=b;i+=k){
        maxNum = max(maxNum,max(nums[((i-1)/k)%(n)],nums[n - ((i-1)/k)%(n)]));
        counter++;
        if(counter>n)break;
        //cout << i << " " << nums[((i-1)/k)%(n)] << " " << nums[n - ((i-1)/k)%(n)] << "\n";
    }
    cout << maxNum;
    return 0;
}
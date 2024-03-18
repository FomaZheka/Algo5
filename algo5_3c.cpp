#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    int n, temp;
    unordered_map<int,int> nums;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> temp;
        nums[temp]++;
    }
    int maxDiff = 0;
    for(auto it:nums){
        maxDiff = max(maxDiff, it.second);
        if(nums.count(it.first - 1)) maxDiff = max(maxDiff,(it.second + nums[it.first - 1]));
        if(nums.count(it.first + 1)) maxDiff = max(maxDiff,(it.second + nums[it.first + 1]));
    }
    cout << n-maxDiff;
    return 0;
}
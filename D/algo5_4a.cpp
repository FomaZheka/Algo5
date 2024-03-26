#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int myUpper(const vector<int>& nums, int n){
    int left = -1;
    int right = nums.size()-1;
    while(left<right){
        int med = (left + right + 1)/2;
        if(nums[med] <= n){
            left = med;
        } else {
            right = med - 1;
        }
    }
    return left;
}

int myLower(const vector<int>& nums, int n){
    int left = 0;
    int right = nums.size();
    while(left<right){
        int med = (left + right)/2;
        if(nums[med] >= n){
            right = med;
        } else {
            left = med + 1;
        }
    }
    return left;
}

int main(){
    int n, temp, k, low, high;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> temp;
        nums[i] = temp;
    }
    sort(nums.begin(),nums.end());
    cin >> k;
    for(int i=0;i<k;i++){
        cin >> low >> high;
        int l = myLower(nums,low);
        int r = myUpper(nums,high);
        cout << myUpper(nums,high) - myLower(nums,low) + 1<< " ";
    }
    return 0;
}
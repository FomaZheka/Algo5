#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    int n, temp, dist;
    bool flag = false;
    unordered_map<int,int> nums;
    cin >> n >> dist;
    for(int i=0;i<n;i++){
        cin >> temp;
        if(!flag){
            if(nums.count(temp)){
                if(i - nums[temp] <= dist) flag = true;
            }
        }
        nums[temp] = i;
    }
    if(!flag) cout << "NO";
    else cout << "YES";
    return 0;
}
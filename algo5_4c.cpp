#include <iostream>
#include <vector>

using namespace std;



int findSubArray(const vector<unsigned long long>& troops, unsigned long long sz, unsigned long long val){
    unsigned long long left = sz;
    unsigned long long right = troops.size() - 1;
    while(left<right){
        unsigned long long med = left + (right-left+1)/2;
        unsigned long long curTroops = troops[med] - troops[med - sz];
        if(curTroops == val) return med - sz + 1;
        if(curTroops < val){
            left = med;
        } else {
            right = med - 1;
        }
    }
    if(left == right && troops[left] == val) return left- sz + 1;
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    unsigned long long n, k, temp, sz, val;
    cin >> n >> k;
    vector<unsigned long long> troops (n+1,0);
    for(unsigned long long i=1;i<=n;i++){
        cin >> temp;
        troops[i] = troops[i-1] + temp;
    }
    for(unsigned long long i=0;i<k;i++){
        cin >> sz >> val;
        cout << findSubArray(troops,sz,val) << "\n";
    }
    return 0;
}
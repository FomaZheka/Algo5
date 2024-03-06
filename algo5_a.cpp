#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    long p, v, q, m;
    cin >> p >> v >> q >> m;
    vector<vector<long>> temp = {{p-v,p+v}, {q-m,q+m}};
    sort(temp.begin(),temp.end());
    vector<vector<long>> vAns;
    int cur = 0;
    while(cur<temp.size()){
        int left = temp[cur][0];
        int right = temp[cur][1];
        while(cur<temp.size() && temp[cur][0] <= right){
            right = max(int(right),int(temp[cur][1]));
            cur++;
        }
        vAns.push_back({left,right});
    }
    long ans = 0;
    for(auto it:vAns){
        ans += (it[1]-it[0]+1);
    }
    cout << ans;
    return 0;
}
#include <iostream>
#include <queue>

using namespace std;

class myComp{
public:
    bool operator()(const pair<int,int>& lhs, const pair<int,int>& rhs){
        if(lhs.first != rhs.first) return lhs.first > rhs.first;
        return lhs.second > rhs.second;
    }
};

int main(){
    int n, k ,temp;
    cin >> n >> k;
    priority_queue<pair<int,int>,vector<pair<int,int>>,myComp> pq;
    int ans = 0;
    for(int i = 0;i<n;i++){
        cin >> temp;
        pq.push({temp,i});
        while(i - pq.top().second > k){
            pq.pop();
        }
        ans = max(temp - pq.top().first, ans);
    }
    cout << ans;
    return 0;
}
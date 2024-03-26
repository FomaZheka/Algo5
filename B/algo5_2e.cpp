#include <iostream>
//#include <algorithm>
#include <queue>
#include <string>

using namespace std;

class MyComp{
public:
    bool operator() (const vector<long long>& lhs, const vector<long long>& rhs){
        return lhs[1] > rhs[1];
    }
};

class MyCompNegative{
public:
    bool operator() (const vector<long long>& lhs, const vector<long long>& rhs){
        return lhs[0] < rhs[0];
    }
};

int main(){
    long long n, a, b;
    long long cur = 0;
    long long ans = 0;
    priority_queue<vector<long long>, vector<vector<long long>>, MyComp> pq;
    priority_queue<vector<long long>, vector<vector<long long>>, MyCompNegative> pqNegative;
    cin >> n;
    for(long long i=0;i<n;i++){
        cin >> a >> b;
        if(a - b < 0){
            pqNegative.push({a,b,i+1});
        } else {
            pq.push({a,b,i+1});
        }
        
    }
    string ansStr;
    bool flag = true;
    while(!pq.empty()){
        cur += pq.top()[0];
        if(cur > ans) ans = cur;
        //cout  << "True " << pq.top()[0] - pq.top()[1] << " " << pq.top()[2] << " " << ans << " " << cur << "\n";
        cur -= pq.top()[1];
        ansStr += to_string(pq.top()[2]);
        ansStr += " ";
        pq.pop();
    }
    if(!pqNegative.empty()){
        cur += pqNegative.top()[0];
        if(cur > ans) ans = cur;
    }
    while(!pqNegative.empty()){
        //cout  << "False " << pqNegative.top()[2] << "\n";
        ansStr += to_string(pqNegative.top()[2]);
        ansStr += " ";
        pqNegative.pop();
    }
    cout << ans << "\n" << ansStr;
    return 0;
}

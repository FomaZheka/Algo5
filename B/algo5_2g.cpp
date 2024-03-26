#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int q, n, temp;
    cin >> q;
    for(int i=0;i<q;i++){
        cin >> n;
        vector<int> vAns;
        int sz = 0;
        int maxSZ = 1000001;
        for(int i=0;i<n;i++){
            cin >> temp;
            maxSZ = min(maxSZ, temp);
            if(sz >= maxSZ){
                vAns.push_back(sz);
                sz = 0;
                maxSZ = temp;
            }
            sz++;
        }
        if(sz>0)vAns.push_back(sz);
        cout<<vAns.size()<<"\n";
        for(int i=0;i<vAns.size();i++){
            cout<<vAns[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

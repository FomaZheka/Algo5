#include <iostream>

using namespace std;


int main()
{
    int n, temp;
    cin >> n;
    long long ans = 0;
    for(int i=0;i<n;i++){
        cin >> temp;
        ans += temp/4;
        int ost = temp%4;
        if(ost > 0){
            if(ost==1) ans+=1;
            else ans+=2;
        }
    }
    cout << ans;
    return 0;
}

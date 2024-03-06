#include <iostream>

using namespace std;

int main()
{
    long long n, temp;
    bool neg = false;
    string ans = "";
    cin >> n;
    cin >> temp;
    if(temp%2!=0) neg = true;
    for(int i=1;i<n;i++){
        cin >> temp;
        if(temp%2==0) ans+='+';
        else {
            if(!neg) ans+='+';
            else ans+='x';
            neg = true;
        }
    }
    
    cout << ans;
    return 0;
}

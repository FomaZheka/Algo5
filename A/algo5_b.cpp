#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int home;
    string str, str2;
    vector<int> score1(2,0);
    vector<int> score2(2,0);
    cin >> str;
    cin >> str2;
    cin >> home;
    if(home == 1){
        score1[0] = str[0] - '0';
        score1[1] = str2[0] - '0';
        score2[1] = str[2] - '0';
        score2[0] = str2[2] - '0';
    } else {
        score1[1] = str[0] - '0';
        score1[0] = str2[0] - '0';
        score2[0] = str[2] - '0';
        score2[1] = str2[2] - '0';
    }
    int diff = (score2[0]+score2[1]) - (score1[0]+score1[1]);
    if(diff < 0) cout << 0;
    else {
        if(home==1){
            if(score2[1]<score1[1]+diff) cout << diff;
            else cout << diff+1;
        } else {
            if(score2[1]<score1[1]) cout << diff;
            else cout << diff+1;
        }
    }
    return 0;
}
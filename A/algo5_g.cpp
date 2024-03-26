#include <iostream>
#include <climits>

using namespace std;

int main()
{
    long long x,y,p;
    long long MinAns = LLONG_MAX;
    long long ans = 0;
    cin >> x >> y >> p;
    long long enemy = 0;
    while(x>0 && (y>0 || enemy>0) && ans < MinAns){
        int actionsKill = x;
        int actionsDest = 0;
        int prevY = y;
        if(y <= x){
            int tempAns = ans+1;
            int tempEnemy = enemy - (x - y);
            int tempX = x - tempEnemy;
            while(tempX>0 && tempEnemy>0){
                tempEnemy-=tempX;
                tempX-=tempEnemy;
                tempAns++;
                if(tempAns > MinAns) break;
            }
            if(tempX>0){
                if(tempAns < MinAns){
                    MinAns = tempAns;
                }
            }
        }
        actionsKill = min(enemy,x);
        actionsDest = x - actionsKill;
        enemy -= actionsKill;
        y -= actionsDest;
        if(enemy>0) x -= enemy;
        enemy+=p;
        if(prevY == y) x=0;
        ans++;
    }
    if(MinAns == LLONG_MAX) cout << -1;
    else cout << MinAns;
    return 0;
}

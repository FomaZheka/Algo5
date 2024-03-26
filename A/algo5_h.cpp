#include <iostream>
#include <float.h>
#include <math.h>
#include <iomanip>
#include <set>

using namespace std;

int main()
{
    double circle, s1, v1, s2, v2, ans, p;
    cin >> circle >> s1 >> v1 >> s2 >> v2;
    if(fabs(s1 - s2) < 0.00000001){
        p = 0.;
        cout << "YES\n"<<fixed << setprecision(10)<<p;
        return 0;
    }
    /*if(s1 > s2){
        double temp = s2;
        s2 = s1;
        s1 = temp;
        temp = v2;
        v2 = v1;
        v1 = temp;
    }*/
    ans = DBL_MAX;
    set<double> answer;
    for(int i=0;i<1000;i++){
        if(fabs(v1 - v2) >= 0.000001){
            p = (s2-s1+circle*i)/(v1-v2);
            if(p>=0.) answer.insert(p);
            p = (s2-s1-circle*i)/(v1-v2);
            if(p>=0.) answer.insert(p);
        }
        if(fabs(v1 + v2) >= 0.000001){
            p = (-s2-s1+circle*i)/(v1+v2);
            if(p>=0.) answer.insert(p);
            p = (-s2-s1-circle*i)/(v1+v2);
            if(p>=0.) answer.insert(p);
        }
        if(answer.size()>2) i =1001;
    }
    if(answer.size()>0){
        cout << "YES\n" <<fixed<<setprecision(10)<< *answer.begin();
    } else {
        cout << "NO";
    }
    return 0;
}

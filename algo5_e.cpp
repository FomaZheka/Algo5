#include <iostream>

using namespace std;


int main()
{
    long long n,k,d;
    cin >> n >> k >> d;
	n*=10;
	for(int i=0;i<10;i++){
    	if((n+i)%k == 0){
        	cout << n + i;
        	for(long long j=0;j<d-1;j++){
        		cout << "0";
        	}
        	return 0;
        }
	}
	cout << "-1";
    return 0;
}

#include <iostream>
#include <unordered_map>
#include <vector>


using namespace std;


vector<string> DAY = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
vector<string> MONTH {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int main()
{
    unordered_map<string, unordered_map<int,string>> year;
    unordered_map<string, int> freeDays = {{"Monday",0},{"Tuesday",0},{"Wednesday",0},{"Thursday",0},{"Friday",0},{"Saturday",0},{"Sunday",0}};
    unordered_map<string, vector<int>> holidays;
    int y, n, d;
    string str;
    cin >> n >> y;
    for(int i=0;i<n;i++){
        cin >> d >> str;
        holidays[str].push_back(d);
    }
    cin >> str;
    vector<string>::iterator itDay = DAY.begin();
    while(*itDay!=str)itDay++;
    for(auto itMon:MONTH){
        int dayInMonth = 31;
        if(itMon == "April" || itMon == "June" || itMon == "September"  || itMon == "November"){
            dayInMonth = 30;
        } else if (itMon == "February"){
            if(y%400 == 0 || (y%4==0 && y%100!=0)) dayInMonth = 29;
            else dayInMonth = 28;
        }
        for(int i=1;i<=dayInMonth;i++){
            year[itMon][i] = *itDay++;
            if(itDay==DAY.end())itDay = DAY.begin();
            freeDays[year[itMon][i]]++;
        }
    }
    for(auto itMon:holidays){
        for(int i:itMon.second){
            freeDays[year[itMon.first][i]]--;
        }
    }
    int minDay = 367;
    string minMonthStr = "";
    int maxDay = -1;
    string maxMonthStr = "";
    for(auto it:freeDays){
        if(it.second < minDay){
            minDay = it.second;
            minMonthStr = it.first;
        }
        if(it.second > maxDay){
            maxDay = it.second;
            maxMonthStr = it.first;
        }
    }
    cout << maxMonthStr << " " << minMonthStr;
    return 0;
}

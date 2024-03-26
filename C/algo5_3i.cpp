#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <iomanip>
//#include <fstream>

using namespace std;

class MatchHelper{
public:
    pair<string,int> parseGoals(string team, int n){
        int firstGoal = 100;
        string firstScorer = ""; 
        int minute;
        string player, line;
        for(int i=0;i<n;i++){
            getline(cin,line);
            player = line.substr(0,line.find_last_of(' '));
            minute = stoi(line.substr(line.find_last_of(' ')+1,line.length()-1));
            if(firstGoal == 100) {
                firstGoal = minute;
                firstScorer = player;
            }
            playerGoals[player]++;
            playerTeam[player] = team;
            if(!teamGoalsByMinute.count(team)) teamGoalsByMinute[team] = vector<int> (91,0);
            teamGoalsByMinute[team][minute]++;
            if(!playerGoalsByMinute.count(player)) playerGoalsByMinute[player] = vector<int> (91,0);
            playerGoalsByMinute[player][minute]++; 
        }
        teamGoals[team]+=n;
        teamMatches[team]++;
        return {firstScorer,firstGoal};
    }

    void parseMatch(string s){
        string teamHome, teamAway, temp;
        int scoreHome, scoreAway, totalGoals;
        int posDel = s.find('-');
        int posLast = s.find_last_of('"');
        teamHome = s.substr(0,posDel-1);
        teamAway = s.substr(posDel+2,posLast - posDel - 1);
        string score = s.substr(posLast+2,s.length()-1-posLast);
        int pos = score.find(':');
        string s1 = score.substr(0,pos);
        string s2 = score.substr(pos+1,score.length()-1-pos);
        scoreHome = stoi(s1);
        scoreAway = stoi(s2);
        totalGoals = scoreHome + scoreAway;
        pair<string,int> pHome = parseGoals(teamHome,scoreHome);
        pair<string,int> pAway = parseGoals(teamAway,scoreAway);
        if(pHome.second <= pAway.second){
            if(pHome.second != 100){
                openGoals[teamHome]++;
                openGoals[pHome.first]++;
            }
        } else {
            openGoals[teamAway]++;
            openGoals[pAway.first]++;
        }
    }

    void requstTotalGoalsTeam(string& req){
        string team = req.substr(16,req.length()-16);
        if(!teamGoals.count(team)){
            cout << "0\n";
        } else {
            cout << teamGoals[team] << "\n";
        }
    }

    void requestTotalGoalsByPlayer(string& req){
        string player = req.substr(15,req.length()-15);
        if(!playerGoals.count(player)){
            cout << "0\n";
        } else {
            cout << playerGoals[player] << "\n";
        }
    }

    void requstMeanGoalsTeam(string& req){
        string team = req.substr(24,req.length()-24);
        cout << setprecision(5) << (teamGoals[team]*1.)/(teamMatches[team]*1.) << "\n";
    }

    void requstMeanGoalsByPlayer(string& req){
        string player = req.substr(23,req.length()-23);
        cout << setprecision(5) << (playerGoals[player]*1.)/(teamMatches[playerTeam[player]]*1.) << "\n";
    }

    void requestGoalsOnMinuteByPlayer(string& req){
        int pos = req.find("by");
        int minute = stoi(req.substr(16,pos-17));
        string player = req.substr(pos+3, req.length()-1-pos);
        if(!playerGoalsByMinute.count(player)) playerGoalsByMinute[player] = vector<int> (91,0);
        cout << playerGoalsByMinute[player][minute] <<"\n";
    }

    void requestGoalsOnFirstMinutes(string& req){
        int pos = req.find("minutes");
        int minute = stoi(req.substr(15,pos-16));
        int posBy = req.find("by");
        string player = req.substr(posBy+3, req.length()-1-posBy);
        if(!playerGoalsByMinute.count(player)) playerGoalsByMinute[player] = vector<int> (91,0);
        int total = 0;
        for(int i=0;i<=minute;i++){
            total+=playerGoalsByMinute[player][i];
        }
        cout << total <<"\n";
    }

    void requestGoalsOnLastMinutes(string& req){
        int pos = req.find("minutes");
        int minute = stoi(req.substr(14,pos-15));
        int posBy = req.find("by");
        string player = req.substr(posBy+3, req.length()-1-posBy);
        if(!playerGoalsByMinute.count(player)) playerGoalsByMinute[player] = vector<int> (91,0);
        int total = 0;
        for(int i=91-minute;i<=90;i++){
            total+=playerGoalsByMinute[player][i];
        }
        cout << total <<"\n";
    }

    void requestOpenGoals(string& req){
        string team = req.substr(15,req.length()-15);
        cout << openGoals[team] << "\n";
    }

private:
    unordered_map<string,int> teamGoals;
    unordered_map<string,int> playerGoals;
    unordered_map<string,int> teamMatches;
    unordered_map<string,string> playerTeam;
    unordered_map<string,vector<int>> teamGoalsByMinute;
    unordered_map<string,vector<int>> playerGoalsByMinute;
    unordered_map<string,int> openGoals;
};





int main(){
    MatchHelper mh;
    string task;
    int req = 0;
    while(getline(cin,task)){
        //Match
        if(task[0]=='"'){
            mh.parseMatch(task);
        } else {
            req++;
            if(req > 125){
                int a=0;a++;
            }
        //Request
            if(task.starts_with("Total goals for")){
                mh.requstTotalGoalsTeam(task);
            } else if(task.starts_with("Mean goals per game for")){
                mh.requstMeanGoalsTeam(task);
            } else if(task.starts_with("Total goals by")){
                mh.requestTotalGoalsByPlayer(task);
            } else if(task.starts_with("Mean goals per game by")){
                mh.requstMeanGoalsByPlayer(task);
            } else if(task.starts_with("Goals on minute")){
                mh.requestGoalsOnMinuteByPlayer(task);
            } else if(task.starts_with("Goals on first")){
                mh.requestGoalsOnFirstMinutes(task);
            } else if(task.starts_with("Goals on last")){
                mh.requestGoalsOnLastMinutes(task);
            } else if(task.starts_with("Score opens by")){
                mh.requestOpenGoals(task);
            }
        }
    }
    return 0;
}
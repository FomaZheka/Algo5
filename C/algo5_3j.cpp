#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class LarisaP2P{
public:
    LarisaP2P(int n, int k): _devices(n), _parts(k) {
        for(int i=0;i<_devices;i++) _relationships[i] = vector<int>(_devices,0);
        for(int i=0;i<_parts;i++) {
            _havingPartsByDevice[0].insert(i);
            //_CountPartsOnAllDevices[i]++;
            _partsOnDevices[i].insert(0);
        }
        _devicesUpdateTime = vector<int>(_devices,0);
        _time = 1;
    }

    vector<int> startUpdate(){
        while(!isUpdated()){
            vector<int> neededParts = findNeededPart();
            unordered_map<int,vector<int>> devicesToAsk;
            vector<int> askedDev(_devices,-1);
            for(int i=1;i<neededParts.size();i++){
                if(neededParts[i]==-1) continue;
                int asked = chooseDeviceToAsk(i,neededParts[i]);
                devicesToAsk[asked].push_back(i);
                askedDev[i]=asked;
            }
            vector<int> approved;
            for(auto itDev:devicesToAsk){
                approved.push_back(answerToDevice(itDev.first,itDev.second));
            }
            for(int i=0;i<approved.size();i++){
                int dev = approved[i];
                int part = neededParts[dev];
                _havingPartsByDevice[dev].insert(part);
                //_CountPartsOnAllDevices[part]++;
                _partsOnDevices[part].insert(dev);
                _relationships[dev][askedDev[dev]]++;
                if(_havingPartsByDevice[dev].size() == _parts) _devicesUpdateTime[dev] = _time;
            }
            _time++;
        }
        return _devicesUpdateTime;
    }


protected:
    bool isUpdated(){
        for(int i=1;i<_devicesUpdateTime.size();i++){
            if(_devicesUpdateTime[i]==0) return false;
        }
        return true;
    }

    int choosePart(int dev){
        int minPart = 0;
        for(int i=0;i<_parts;i++){
            if(!_havingPartsByDevice[dev].count(i)){
                minPart = i;
                break;
            }
        }
        for(int i=minPart+1;i<_parts;i++){
            if(_partsOnDevices[i].size() < _partsOnDevices[minPart].size() && !_havingPartsByDevice[dev].count(i)){
                minPart = i;
            }
        }
        return minPart;
    }

    int chooseDeviceToAsk(int dev, int part){
        int chosenOne = 0;
        for(auto itDevice:_partsOnDevices[part]){
            if(_havingPartsByDevice[itDevice].size() < _havingPartsByDevice[chosenOne].size()){
                chosenOne = itDevice;
            } else if(_havingPartsByDevice[itDevice].size() == _havingPartsByDevice[chosenOne].size() && itDevice < chosenOne) {
                chosenOne = itDevice;
            }
        }
        return chosenOne;
    }

    int answerToDevice(int dev, const vector<int>& asked){
        int ans = asked[0];
        for(int i=1;i<asked.size();i++){
            int newAsk = asked[i];
            if(_relationships[dev][newAsk] > _relationships[dev][ans]){
                ans = newAsk;
            } else if (_relationships[dev][newAsk] == _relationships[dev][ans]){
                if(_havingPartsByDevice[newAsk].size() < _havingPartsByDevice[ans].size()){
                    ans = newAsk;
                } else if(_havingPartsByDevice[newAsk].size() == _havingPartsByDevice[ans].size() && newAsk < ans){
                    ans = newAsk;
                }
            }
        }
        return ans;
    }

    vector<int> findNeededPart(){
        vector<int> res(_devices,-1);
        for(int i=1;i<_devices;i++){
            if(_havingPartsByDevice[i].size() < _parts){
                res[i] = choosePart(i);
            }
        }
        return res;
    }




//----------------------------------------------------------------------

    int _devices;
    int _parts;
    int _time;
    //key - Dev, val - parts
    unordered_map<int,unordered_set<int>> _havingPartsByDevice;
    //key - part, val - counts
    //unordered_map<int,int> _need;
    //key - part, val - list of Devices
    unordered_map<int,unordered_set<int>> _partsOnDevices;
    //key - dev, part - relation to other dev
    unordered_map<int,vector<int>> _relationships;
    //updateTime
    vector<int> _devicesUpdateTime;

};




int main(){
    int n, k;
    cin >> n >> k;
    LarisaP2P larisa(n,k);
    vector<int> ans = larisa.startUpdate();
    for(int i=1;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    return 0;
}
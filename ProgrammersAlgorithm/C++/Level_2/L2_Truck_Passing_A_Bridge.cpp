#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;
    vector <pair<int,int>> truck;

    while(1){

        if(!truck_weights.empty() && weight >= truck_weights[0]){
            weight -= truck_weights[0];
            truck.push_back(pair<int,int>(truck_weights[0],0));

            truck_weights.erase(truck_weights.begin());            
        }

        for(int i=0;i<truck.size();i++){
            truck[i].second++;
        }

        if(truck[0].second == bridge_length){
            weight += truck[0].first;
            truck.erase(truck.begin());
        }
        time ++;

        if(truck.empty() && truck_weights.empty()) break;

    }

    return ++time;
}
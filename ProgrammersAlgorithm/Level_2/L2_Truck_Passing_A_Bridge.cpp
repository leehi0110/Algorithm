#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int time, int weight, vector<int> truck_weights) {
    int answer = 0;
    deque <int> times;
    deque <int> ontheBridge;
    
    times.push_back(time+1); // 시간 추가
    weight -= truck_weights[0]; // 남은 다리 무게 계산
    ontheBridge.push_back(truck_weights[0]); // 다리에 있는 트럭의 무게들
    truck_weights.erase(truck_weights.begin()); // 남은 트럭
    
    cout << "truck weights = ";
    for(int i : truck_weights){
        cout << i << " ";
    }
    cout << endl;
    
    cout << "time stack = ";
    for(int i : times){
        cout << i << " ";
    }
    cout << endl;
    
    cout << "ontheBridge = ";
    for(int i : ontheBridge){
        cout << i << " ";
    }
    cout << endl;
    
    while(!truck_weights.empty()){
        if(weight - truck_weights[0] >= 0){ // 다리에 트럭이 더 올라갈 수 있는 경우
            weight -= truck_weights[0]; // 남은 다리의 무게
            ontheBridge.push_back(truck_weights[0]); // 다리에 있는 트럭의 무게들
            times.push_back(times.back()+1); // 시간 추가
            
            truck_weights.erase(truck_weights.begin()); // 남은 트럭
            
                cout << "truck weights = ";
                for(int i : truck_weights){
                    cout << i << " ";
                }
                cout << endl;

                cout << "time stack = ";
                for(int i : times){
                    cout << i << " ";
                }
                cout << endl;

                cout << "ontheBridge = ";
                for(int i : ontheBridge){
                    cout << i << " ";
                }
                cout << endl;
        }
        else { // 다리에 트럭이 더 이상 올라갈 수 없는 경우
            weight += ontheBridge.front();
            ontheBridge.pop_front();
            
            times.push_back(times.back()+(times.back()-times.front())+time);
            times.pop_front();
            
            weight -= truck_weights[0];
            ontheBridge.push_back(truck_weights[0]);
            truck_weights.erase(truck_weights.begin());
            
            cout << "truck weights = ";
            for(int i : truck_weights){
                cout << i << " ";
            }
            cout << endl;

            cout << "time stack = ";
            for(int i : times){
                cout << i << " ";
            }
            cout << endl;

            cout << "ontheBridge = ";
            for(int i : ontheBridge){
                cout << i << " ";
            }
            cout << endl;
        }
    }
    
    answer = times.back();
    
    return answer;
}
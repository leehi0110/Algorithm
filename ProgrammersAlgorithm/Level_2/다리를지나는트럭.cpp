// ProblemNumber || ProblemName : 다리를 지나는 트럭
// 문제
// 모든 트럭이 다리를 지나는데 걸리는 시간을 구하라

#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

int solution(int len, int weight, vector<int> weights) {
    int answer = 0;
    deque<int> bridge(len,0);
    
    while(1) {
        answer++;
        weight += bridge.front();
        bridge.pop_front();
        
        if(!weights.empty() && weights[0] <= weight) {
            weight -= weights[0];
            bridge.push_back(weights[0]);
            weights.erase(weights.begin());
        }
        else {
            bridge.push_back(0);
        }
        
        if(weights.empty() && *max_element(bridge.begin(), bridge.end()) == 0) break;
    }
    
    return answer;
}

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {

    int order = 1;

    while(1){
        
        int max = *max_element(priorities.begin(),priorities.end());

        if(location == 0){
            if(max == priorities[0]) break;
            else {
                priorities.push_back(priorities[0]);
                priorities.erase(priorities.begin());
                location = priorities.size()-1;
            }
        }
        else { // location != 0
            if(max == priorities[0]) {
                order ++;
                priorities.erase(priorities.begin());
                location --;
            }
            else {
                priorities.push_back(priorities[0]);
                priorities.erase(priorities.begin());
                location --;
            }
        }
    
    }

    return order;
}
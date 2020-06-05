#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    
    sort(d.begin(),d.end());
    
    for(int val : d){
        if(budget - val >= 0) {
            budget -= val;
            answer ++;
        }
        else break;
    }
    
    return answer;
}
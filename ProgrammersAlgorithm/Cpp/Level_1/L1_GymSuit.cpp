#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    
    for(int i=0;i<lost.size();i++){
        vector<int>::iterator iter;
        
        iter = find(reserve.begin(),reserve.end(),lost[i]);
        if(iter == reserve.end()) continue;
        else {
            answer ++;
            reserve.erase(iter);
            iter = lost.begin() + i;
            lost.erase(iter);
            i--;
        }
    }
    
    for(int i=0;i<reserve.size();i++){
        vector<int>::iterator iter;
        
        iter = find(lost.begin(),lost.end(),reserve[i]-1);
        if(iter == lost.end()) {
            iter = find(lost.begin(),lost.end(),reserve[i]+1);
            if(iter == lost.end()) continue;
             else {
                 answer ++;
                 lost.erase(iter);
                 iter = reserve.begin() + i;
                 reserve.erase(iter);
                 i--;
             }
        }
        else {
            answer ++;
            lost.erase(iter);
            iter = reserve.begin() + i;
            reserve.erase(iter);
            i --;
        }
    }
    
    return answer;
}
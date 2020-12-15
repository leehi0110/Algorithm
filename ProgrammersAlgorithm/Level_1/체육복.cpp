// ProblemNumber || ProblemName : 체육복
// 문제
// 체육 수업을 들을 수 있는 학생의 수를 반환하시오

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int>::iterator reserve_iter;
    vector<int>::iterator lost_iter;
    
    for(int i=0;i<lost.size();i++){
        
        reserve_iter = find(reserve.begin(),reserve.end(),lost[i]);

        if(reserve_iter != reserve.end()) {
            lost_iter = find(lost.begin(),lost.end(),lost[i]);
            reserve.erase(reserve_iter);
            lost.erase(lost_iter);
            i--;
            continue;
        }
    }
    
    for(int i=0;i<lost.size();i++){
        
        reserve_iter = find(reserve.begin(),reserve.end(),lost[i]-1);
        if(reserve_iter != reserve.end()){
            lost_iter = find(lost.begin(),lost.end(),lost[i]);
            
            reserve.erase(reserve_iter);
            lost.erase(lost_iter);
            i--;
            continue;
        }
        
        reserve_iter = find(reserve.begin(),reserve.end(),lost[i]+1);
        if(reserve_iter != reserve.end()){
            lost_iter = find(lost.begin(),lost.end(),lost[i]);
            
            reserve.erase(reserve_iter);
            lost.erase(lost_iter);
            i--;
            continue;
        }
    }
    
    return (n-lost.size());
}
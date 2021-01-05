// ProblemNumber || ProblemName : K번째 수
// 문제
// 배열 array의 i번째 숫자부터 j번째 숫자까지 자르고 정렬했을 때, k번째에 있는 수를 구하라

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i=0;i<commands.size();i++){
        vector<int>::iterator start = array.begin() + commands[i][0]-1;
        vector<int>::iterator end = array.begin() + commands[i][1];
            
        vector<int> temp(commands[i][1] - commands[i][0]+1,0);
        
        temp.assign(start,end);
        
        sort(temp.begin(),temp.end());
        
        answer.push_back(temp[commands[i][2]-1]);
    }
    
    return answer;
}

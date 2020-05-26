#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> aPick {1,2,3,4,5};
    vector<int> bPick {2,1,2,3,2,4,2,5};
    vector<int> cPick {3,3,1,1,2,2,4,4,5,5};
    vector<int> score(3);
    
    for(int i=0;i<answers.size();i++){
        if(answers[i] == aPick[i%5]) score[0] ++;
        if(answers[i] == bPick[i%8]) score[1] ++;
        if(answers[i] == cPick[i%10]) score[2] ++;
    }
    
    int maxScore = *max_element(score.begin(),score.end());
    
    for(int i=0;i<3;i++){
        if(score[i] == maxScore) answer.push_back(i+1);
    }
    
    return answer;
}
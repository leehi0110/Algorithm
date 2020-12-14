// ProblemNumber || ProblemName : 모의고사
// 문제
// 최고점을 받은 수포자를 반환하시오

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> aPick {1,2,3,4,5};
    vector<int> bPick {2,1,2,3,2,4,2,5};
    vector<int> cPick {3,3,1,1,2,2,4,4,5,5};

    int aCnt = 0 , bCnt = 0, cCnt = 0;

    for(int i=0;i<answers.size();i++){
        if(answers[i] == aPick[i%5]) aCnt ++;
        if(answers[i] == bPick[i%8]) bCnt ++;
        if(answers[i] == cPick[i%10]) cCnt ++;
    }

    if(aCnt > bCnt){
        if(aCnt > cCnt){
            answer.push_back(1);
        }
        else if(aCnt == cCnt){
            answer.push_back(1);
            answer.push_back(3);
        }
        else {
            answer.push_back(3);
        }
    }
    else if(aCnt < bCnt){
        if(bCnt > cCnt){
            answer.push_back(2);
        }
        else if(bCnt == cCnt){
            answer.push_back(2);
            answer.push_back(3);
        }
        else {
            answer.push_back(3);
        }
    }
    else { // aCnt == bCnt
        if(cCnt > aCnt){
            answer.push_back(3);
        }
        else if(cCnt < aCnt){
            answer.push_back(1);
            answer.push_back(2);
        }
        else {
            answer.push_back(1);
            answer.push_back(2);
            answer.push_back(3);
        }
    }

    return answer;
}

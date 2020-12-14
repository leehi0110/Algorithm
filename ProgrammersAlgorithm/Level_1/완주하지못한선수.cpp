// ProblemNumber || ProblemName : 완주하지 못한선수
// 문제
// 선수 목록과 완주 선수 목록이 주어졌을 때 완주하지 못한 선수를 찾으시오

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    int i;
    
    sort(participant.begin(),participant.end(),less<string>());
    sort(completion.begin(),completion.end(),less<string>());
    
    for(i=0;i<participant.size()-1;i++){
        if(participant[i] != completion[i]) return participant[i];
    }
    return participant[i];
}}

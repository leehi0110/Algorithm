// ProblemNumber || ProblemName : 스킬트리
// 문제
// 유효한 스킬트리의 개수를 반환하시오

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(string s: skill_trees) {
        int index = 0;
        for(int i=0;i<s.length();i++) {
            if(find(skill.begin(),skill.end(),s[i]) != skill.end()) {
                if(skill[index] == s[i]) index++;
                else break;
            }
            if(i == s.length()-1) answer++;
        }
    }
    
    return answer;
}

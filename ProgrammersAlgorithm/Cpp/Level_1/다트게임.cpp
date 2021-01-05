// ProblemNumber || ProblemName : 다트게임
// 문제
// 다트게임의 점수를 구하라

#include <string>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int score = 0;
    vector<int> result;
    
    for(char c: dartResult) {
        if(c == 'S' || c == 'D' || c == 'T'){
            if(c=='S') result.push_back(score);
            else if(c == 'D') result.push_back(pow(score,2));
            else result.push_back(pow(score,3));
            
            score = 0;
        }
        else if(c == '*' || c == '#') {
            int resultSize = result.size();
            
            if(resultSize == 1) {
                c == '*' ? result[0] *=2 : result[0] *= -1;
            }
            else {
                if(c == '*'){
                    result[resultSize-2] *= 2;
                    result[resultSize-1] *= 2; 
                }
                else {
                    result[resultSize-1] *= -1;
                }
            }
        }
        else {
            score = score*10 + c-'0';
        }
    }
    
    answer = accumulate(result.begin(),result.end(),0);
    
    return answer;
}

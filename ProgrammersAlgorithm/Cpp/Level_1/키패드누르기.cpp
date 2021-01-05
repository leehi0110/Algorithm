// ProblemNumber || ProblemName : 키패드 누르기
// 문제
// 어느 손가락으로 키패드를 누르는지 순서를 구하시오

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int moveCnt(int now,int target) {
    
    if(now == target)  return 0;
    else if(abs(target-now) == 1 || abs(target-now) == 3) return 1;
    else if(abs(target-now) == 2 || abs(target-now) == 4 || abs(target-now) == 6) return 2;
    else if(abs(target-now) == 5 || abs(target-now) == 7 || abs(target-now) == 9) return 3;
    else return 4;
    
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int nowLeft = 12;
    int nowRight = 12;
    
    for(int i: numbers) {
        
        if(i == 1 || i == 4 || i == 7) {
            answer += 'L';
            nowLeft = i;
        }
        else if(i == 3 || i == 6 || i == 9) {
            answer += 'R';
            nowRight = i;
        }
        else {
            if(i == 0) i = 11;
            
            int lCnt = moveCnt(nowLeft,i);
            int rCnt = moveCnt(nowRight,i);
            
            if(lCnt == rCnt) {
                if(hand == "left") {
                    answer += 'L';
                    nowLeft = i;
                }
                else {
                    answer += 'R';
                    nowRight = i;
                }
            }
            else if(lCnt < rCnt) {
                answer += 'L';
                nowLeft = i;
            }
            else {
                answer += 'R';
                nowRight = i;
            }
        }
    }
    
    return answer;
}

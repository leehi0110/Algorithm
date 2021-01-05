#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    int laserCnt = 0;
    deque <int> que;

    for(int i=0;i<arrangement.length();i++){
        if(arrangement[i] == '('){
            if(arrangement[i+1] == ')'){
                for(int j=0;j<que.size();j++){
                    que[j] ++;
                }
                i++;
            }
            else {
                que.push_back(1);
            }
        }
        else { // arrangement[i] == ")"
            answer += que.back();
            que.pop_back();
        }
    }
    return answer;
}
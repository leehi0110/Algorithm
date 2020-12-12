#include <string>
#include <algorithm>
#include <iostream>
#include <deque>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int score, first, second;
    deque<int> que;

    for(int i=0;i<dartResult.length();i++){
        if(isdigit(dartResult[i])){
            if(isdigit(dartResult[i+1])){
                que.push_back(10);
                i++;
            }
            else {
                 que.push_back(dartResult[i] - '0');   
            }
        } // 점수에 대한 처리
        else if(dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T'){
            score = que.back();
            que.pop_back();

            if(dartResult[i] == 'S') que.push_back(pow(score,1));
            else if(dartResult[i] == 'D') que.push_back(pow(score,2));
            else que.push_back(pow(score,3));
        } // single, double, triple에 대한 처리
        else {
            if(dartResult[i] == '*'){
                if(que.size() == 1){
                    score = que.back();
                    que.pop_back();
                    que.push_back(score*2);
                }
                else {
                    second = que.back(); 
                    que.pop_back();
                    first = que.back(); 
                    que.pop_back();

                    que.push_back(first*2);
                    que.push_back(second*2);
                }
            }
            else { // dartResult[i] == '#'
                score = que.back();
                que.pop_back();
                que.push_back(score*-1);
            }
        } // 상에 대한 처리

    }

    for(int i: que){
        answer += i;
    }

    return answer;
}
// ProblemNumber || ProblemName : 예산
// 문제
// 예산을 이용해 구매할 수 있는 부서의 최대 수를 구하시오

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    
    sort(d.begin(),d.end());
    
    for(int i: d) {
        if(i <= budget) {
            answer += 1;
            budget -= i;
        }
        else break;
    }
    
    return answer;
}

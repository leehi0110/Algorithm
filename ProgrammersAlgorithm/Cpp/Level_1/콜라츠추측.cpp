// ProblemNumber || ProblemName : 콜라츠 추측
// 문제
// 콜라츠의 추측이 맞는지 확인하시오

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int num) {
    long long temp = num;
    int answer = -1;
    
    while(++answer <= 500) {
        if(temp == 1) return answer;
        
        temp & 1 ? temp = temp*3+1 : temp /= 2;
    }
    
    return -1;
}

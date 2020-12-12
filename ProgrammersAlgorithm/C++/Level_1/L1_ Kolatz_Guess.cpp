#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k) {
    int answer = 0;
    long long num = k;

    while(num != 1){
        num & 1 ? num = num*3 + 1 : num /= 2;
        answer += 1;

        if(answer >= 500) return -1;
    }

    return answer;
}
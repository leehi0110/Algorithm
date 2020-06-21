#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 1;
    int before = 0;

    for(int i = 2;i<=n;i++){
        int tmp = (before + answer)%1234567;
        before = answer;
        answer = tmp;
    }

    return answer;
}
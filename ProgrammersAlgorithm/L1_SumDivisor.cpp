#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    //int sum = 1; //1은 모든숫자의 약수이다.
    for(int i = 1; i < n+1; i++)
    {
        if(n%i == 0) answer+= i;
    }
    return answer;
}
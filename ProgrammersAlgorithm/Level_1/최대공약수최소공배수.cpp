// ProblemNumber || ProblemName : 최대 공약수 최소 공배수
// 문제
// 입력 받은 두 수의 최소공배수와 최대공약수를 구하시오

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int GCD(int a, int b) {
    if(b == 0) return a;
    else return GCD(b,a%b);
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    if(n > m) swap(n,m);
    answer.push_back(GCD(n,m));
    answer.push_back((n*m)/GCD(n,m));
    
    return answer;
}
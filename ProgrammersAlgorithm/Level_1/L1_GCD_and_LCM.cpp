#include <string>
#include <vector>

using namespace std;
int gcd(int a, int b);
int lcm(int a, int b);

vector<int> solution(int n, int m) {
    vector<int> answer;
    answer.push_back(gcd(n,m));
    answer.push_back(lcm(n,m));
    return answer;
}

int gcd(int a, int b) {
    int c;
    while(b != 0) {
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}

int lcm(int a, int b) {
    return a * b /gcd(a,b);
}

// 유클리드호제법
// Greatest Common Divisor
// a, b의 최소공배수
// r = a%b
// b != 0 => a = b => b = r => r = a%b 반복
// b == 0 => a가 최대공약수

// Least Common multiple
// a, b 의 최대공약수
//     최대공약수 * 최소공배수 = a * b
// =>  최대공약수 = (a * b) / GCD(a,b)
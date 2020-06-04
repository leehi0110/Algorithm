#include <string>
#include <vector>

using namespace std;

string solution(int num) {

    return (num+2)%2 == 0 ? "Even" : "Odd";
}

// 비트 연산자로 홀수 판별
// num & 1 ? "Odd" : "Even"
// 홀 수는 xxx1 & 0001 => 0001 이기 때문에 1
// 짝 수는 xxx0 & 0001 => 0000 이기 때문에 0
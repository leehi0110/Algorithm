#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int sum;
    for (int j = 1;j <= n;j++) {
        sum = 0;
        for (int temp = j;sum < n;temp++) {
            sum += temp;
        }
        if (sum == n)   answer++;
    }
    return answer;
}
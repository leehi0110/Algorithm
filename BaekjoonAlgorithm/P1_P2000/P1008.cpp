// Baekjoon 1008
// 문제
// A / B를 출력하시오

#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

int main()
{
    int a,b;

    cin >> a >> b;

    cout.precision(10);
    cout << static_cast<double>(a) / static_cast<double>(b) << endl;

    return 0;
}
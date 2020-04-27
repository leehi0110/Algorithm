// Baekjoon 3053 
// 문제
// 택시 기하학
#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int r;

    cin >> r;

    cout << fixed;
    cout.precision(7);
    cout << pow(r,2)*M_PI << endl;
    cout << 2*pow(r,2) << endl;
}
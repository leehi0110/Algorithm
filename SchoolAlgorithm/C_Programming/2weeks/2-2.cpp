// 2주차
// 변수와 자료형

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    // ios_base :: sync_with_stdio(false);
    // cin.tie(NULL);
    double a, b;

    a = 4.200000;
    b = 5.100000;

    cout.setf(ios::fixed);
    cout.precision(6);
    cout << a + b;
}
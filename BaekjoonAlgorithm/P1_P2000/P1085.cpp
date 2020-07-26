// Baekjoon 1085
// 문제
// 직사각형에서 탈출

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int x,y,w,h;
    int min;

    cin >> x >> y >> w >> h;

    min = x - 0;

    if(w-x < min) min = w -x;
    if(y - 0 < min) min = y - 0;
    if(h - y < min) min = h - y;

    cout << min << endl;
}
// Baekjoon 2588
// 문제
// 곱셈

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a, b;
    int ahun , aten , aone;
    int bhun , bten , bone;

    cin >> a >> b;

    aone = a % 10;
    aten = a / 10 % 10;
    ahun = a / 100;

    bone = b % 10;
    bten = b / 10 % 10;
    bhun = b / 100;

    cout << (aone*bone) + (aten*bone)*10 + (ahun*bone)*100 << endl;
    cout << (aone*bten) + (aten*bten)*10 + (ahun*bten)*100 << endl;
    cout << (aone*bhun) + (aten*bhun)*10 + (ahun*bhun)*100 << endl;
    cout << a * b << endl;
    
    return 0;


}
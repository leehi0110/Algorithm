// Baekjoon 2739
// 문제
// 구구단

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int num;

    cin >> num;

    for(int i=1;i<10;i++){
        cout << num << " * " << i << " = " << num*i << endl;
    }
}
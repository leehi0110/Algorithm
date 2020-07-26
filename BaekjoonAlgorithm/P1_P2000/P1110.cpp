// Baekjoon 1110번
// 문제
// 더하기 사이클

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int a;
    int original;
    int cnt = 0;

    cin >> original;
    a = original;

    do
    {
        if(a < 10){
            a *= 11;
        }
        else {
            a = ((a%10)*10)+(((a/10)+(a%10))%10);
        }
        cnt ++;
    } while (a != original);
    
    cout << cnt << endl;
}
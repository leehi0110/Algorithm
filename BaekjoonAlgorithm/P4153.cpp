// Baekjoon 4153
// 문제
// 직각삼각형

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    int max_val;

    while (1)
    {
        cin >> a >> b >> c;

        if (a == 0 && b == 0 && c == 0)
            break;

        if (a > b){
            if (a > c){
                if(pow(a,2) == pow(b,2) + pow(c,2)) cout << "right" << endl;
                else cout << "wrong" << endl;
            }
            else{
                if(pow(c,2) == pow(a,2) + pow(b,2)) cout << "right" << endl;
                else cout << "wrong" << endl;
            }
        }
        else{
            if (b > c){
                if(pow(b,2) == pow(a,2) + pow(c,2)) cout << "right" << endl;
                else cout << "wrong" << endl;
            }
            else{
                if(pow(c,2) == pow(a,2) + pow(b,2)) cout << "right" << endl;
                else cout << "wrong" << endl;
            }
        }
    }
}
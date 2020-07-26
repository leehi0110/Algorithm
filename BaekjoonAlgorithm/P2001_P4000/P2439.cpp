// Baekjoon 2439
// 문제
// 별 찍기 - 2

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    int blank;
    int star;

    cin >> n;

    blank = n-1;
    star = 1;

    for(int i=0;i<n;i++){
        for(int j=blank;j>0;j--){
            cout << " ";
        }
        for(int j=0;j<star;j++){
            cout << "*";
        }
        cout << '\n';
        blank -= 1;
        star += 1;
    }
}
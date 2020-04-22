// Baekjoon 2523
// 문제
// 별찍기 - 13

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int star = 1;

    cin >> n;

    for(int i=0;i<2*n-1;i++){
        for(int j=0;j<star;j++){
            cout << "*";
        }
        if(i < n-1){
            star ++;
            cout << endl;
        }
        else {
            star --;
            cout << endl;
        }
    }
}
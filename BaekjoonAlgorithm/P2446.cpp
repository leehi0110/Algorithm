// Baekjoon 2446
// 문제
// 별찍기 - 9

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int j;
    int star;
    int blank=0;

    cin >> n;
    star = 2*n-1;

    for(int i=0;i<2*n-1;i++){
        for(j=0;j<blank;j++){
            cout << " ";
        }
        for(j=0;j<star;j++){
            cout << "*";
        }
        if(i < n-1){
            blank ++;
            star -= 2;
            cout << endl;
        }
        else {
            blank --;
            star += 2;
            cout << endl;
        }
        
    }
}
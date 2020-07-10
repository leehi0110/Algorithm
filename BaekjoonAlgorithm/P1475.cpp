// Baekjoon 1475
// 문제
// 방 번호

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n;
    string numberString;
    vector <int> number(9,0);

    cin >> n;

    while(n > 9){
        if(n%10 == 9){
            number[6]++;
        }
        else {
            number[n%10]++;
        }
        n /= 10;
    }
    if(n == 9) number[6]++;
    else number[n]++;

    if(number[6]%2 == 0) number[6] /= 2;
    else number[6] = number[6]/2 + 1;
    int max = 0;

    for(int i=0;i<number.size();i++){
        if(number[i] > max) max = number[i];
    }

    cout << max << endl;
}
// Baekjoon 1978
// 문제
// 소수 찾기

#include <iostream>
#include <vector>
#include <string>

using namespace std;
bool isPrime(int number);

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int cnt = 0;
    int number;

    cin >> n;

    for(int i=0;i<n;i++){
        cin >> number;
        if(isPrime(number)) cnt++;
    }

    cout << cnt << endl;
   
}

bool isPrime(int number)
{
    int j;

    for(j=2;j<number+1;j++){
        
        if(number%j == 0){
            if(j == number){
                return true;
            }
            else return false;
        }
    }
    return false;
}
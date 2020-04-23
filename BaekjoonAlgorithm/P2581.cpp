// Baekjoon 2581
// 문제
// 소수

#include <iostream>
#include <vector>
#include <string>

using namespace std;
bool isPrime(int number);

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int max, min;
    int min_prime, sum_prime=0;

    cin >> min;
    cin >> max;

    for(int i=max;i>min-1;i--){
        if(isPrime(i)){
            sum_prime += i;
            min_prime = i;
        }
    }
    
    if(sum_prime == 0){
        cout << -1 << endl;
    }
    else cout << sum_prime << endl << min_prime << endl;
}

bool isPrime(int number)
{
    int j;

    for(j=2;j<number+1;j++){
        if(number%j == 0){
            if(number == j){
                return true;
            }
            else return false;
        }
    }

    return false;
}
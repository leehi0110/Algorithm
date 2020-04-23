// Baekjoon 1929 
// 문제
// 소수구하기 - 에라스토테네스의 체

#include <iostream>
#include <vector>
#include <string>

using namespace std;
bool isPrime(int number);

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    long int min,max;

    cin >> min >> max;

    vector <bool> array(max+1,true); // true 초기화

    array[0] = false;
    array[1] = false;

    for(long int i=2;i<max+1;i++){
        if(array[i]){
            for(int j=i*2;j<max+1;j += i){
                array[j] = false;
            }
        } // 소수 일 경우
    }

    for(long int i=min;i<max+1;i++){
        if(array[i]) cout << i << "\n";
    }

}

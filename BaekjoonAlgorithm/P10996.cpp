// Baekjoon 10996
// 문제
// 별 찍기 - 21

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int n,i,j;
    int even, odd;

    cin >> n;

    if(n%2 ==0 ){
        odd = n-1;
        even = n;
    } // n이 짝수
    else {
        odd = n;
        even = n-1;
    } // n이 홀수

    if(n == 1){
        cout << "*" << endl;
    } // 예외처리
    else {
        for(i=0;i<2*n;i++){

            if((i+1)%2 != 0){
                for(j=0;j<odd+1;j++){
                    if((j+1)%2 == 0){
                        cout << " ";
                    }
                    else {
                        cout << "*";
                    }
                }
                cout << endl;
            } // 홀수 층
            else { // even 2 odd 3
                for(j=0;j<even+1;j++){
                    if((j+1)%2 == 0){
                        cout << "*";
                    }
                    else {
                        cout << " ";
                    }
                }

                cout << endl;
            } // 짝수 층
        } // for-column

    } // n이 2 이상
}
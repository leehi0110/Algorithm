// Baekjoon 10871
// 문제
// X보다 작은 수

#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);

    int n, x;
    int num;

    cin >> n >> x;

    for(int i = 0; i<n;i++){
        cin >> num;
        if(num < x){
            cout << num << " ";
        } 
    }
}
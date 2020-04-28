// Baekjoon 10872
// 문제
// 팩토리얼

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int result = 1;

    cin >> n;

    for(int i=n;i>0;i--){
        result *= i;
    }

    cout << result << endl;
    
}
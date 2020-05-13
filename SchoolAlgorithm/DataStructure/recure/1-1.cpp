// 1주차
// 재귀함수-1

#include <iostream>
#include <vector>
#include <string>

int recure_sum(int num);
using namespace std;

int main()
{
    // ios_base :: sync_with_stdio(false);
    // cin.tie(NULL);
    
    int n;

    cin >> n;

    cout << recure_sum(n);
}

int recure_sum(int num)
{
    if(num == 1) {
        return num;
    }
    else {
        return recure_sum(num-1) + num;
    }
}
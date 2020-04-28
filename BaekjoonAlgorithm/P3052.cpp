// Baekjoon 3052
// 문제
// 나머지

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int cnt = 0;
    int val;
    vector <bool> check(1001,false);

    for(int i=0;i<10;i++){
        cin >> val;
        if(check[val%42]) continue;
        else {
            cnt ++;
            check[val%42] = true;
        }
    }

    cout << cnt << endl;
}
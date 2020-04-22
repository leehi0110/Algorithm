// Baekjoon 2869 
// 문제 
// 달팽이는 올라가고 싶다

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    long int a,b,v;
    int day=0;

    cin >> a >> b >> v;

    if((v-a)%(a-b) != 0){
        day = (v-a)/(a-b)+2;
    }
    else {
        day = (v-a)/(a-b)+1;
    }

    cout << day << endl;
}

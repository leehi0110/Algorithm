// Baekjoon 2292
// 문제
// 벌집

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    long int n;
    long int position = 1;
    int take = 1;

    cin >> n;

    while(n > position){
        position += take*6;
        take++;
    }

    cout << take << endl;

}
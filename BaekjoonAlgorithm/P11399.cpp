// Baekjoon 11399
// 문제
// ATM

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main()
{
    int n;
    int sum = 0;
    int tmp = 0;
    multiset <int> times;
    multiset <int>::iterator iter;

    cin >> n;

    for(int i=0;i<n;i++){
        int time;
        cin >> time;
        times.insert(time);
    }

    for(int time : times){
        tmp += time;
        sum += tmp;
    }

    cout << sum << endl;
}

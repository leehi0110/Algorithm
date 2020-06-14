// Baekjoon 11047
// 문제
// 동전 0

#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;

int main()
{
    int n, k;
    int answer = 0;
    deque <int> que;

    cin >> n >> k;

    for(int i=0;i<n;i++){
        int coin;
        
        cin >> coin;
        que.push_front(coin);
    }

    for(int i=0;i<que.size();i++){
        if(k >= que[i]){
            answer += k/que[i];
            k -= (k/que[i])*que[i];
        }

        if(k == 0) break;
    }

    cout << answer << endl;
}
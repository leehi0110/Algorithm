// Baekjoon 11279
// 문제
// 최대 힙

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    priority_queue <int> que;

    cin >> n;

    for(int i=0;i<n;i++){
        int cmd;

        cin >> cmd;
        if(cmd == 0) {
            if(que.empty()) cout << 0 << "\n";
            else {
                cout << que.top() << "\n";
                que.pop();
            }
        }
        else {
            que.push(cmd);
        }
    }
}
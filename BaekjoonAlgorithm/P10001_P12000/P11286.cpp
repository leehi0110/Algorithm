// Baekjoon 11286
// 문제
// 절대값 힙

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    multiset <pair<int,int>> heap;
    multiset <pair<int,int>>::iterator iter;
    int cmd_num;

    cin >> cmd_num;

    for(int i=0;i<cmd_num;i++){
        int val;

        cin >> val;

        if(!val && heap.empty()) cout << 0 << "\n";
        else if(!val){
            iter = heap.begin();
            cout << iter->second << "\n";
            heap.erase(iter);
        }
        else {
            heap.insert(pair<int,int>(abs(val),val));
        }
    }

}

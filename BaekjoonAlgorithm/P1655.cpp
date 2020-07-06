// Baekjoon 1655
// 문제
// 가운데를 말해요

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
    
    priority_queue <int,vector<int>> max_heap;
    priority_queue <int,vector<int>,greater<int>> min_heap;

    int n;

    cin >> n;

    while(n--){
        int temp;
        cin >> temp;

        if(max_heap.size() == min_heap.size()){
            max_heap.push(temp);
        }
        else {
            min_heap.push(temp);
        }

        if(!min_heap.empty() && max_heap.top() > min_heap.top()) {
            int go_to_max_heap = min_heap.top();
            int go_to_min_heap = max_heap.top();

            min_heap.pop();
            max_heap.pop();

            min_heap.push(go_to_min_heap);
            max_heap.push(go_to_max_heap);
        }

        cout << max_heap.top() << endl;
    }
}
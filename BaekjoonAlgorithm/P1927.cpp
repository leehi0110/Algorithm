// Baekjoon 1927
// 문제
// 최소 힙

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    multiset <int> heap;
    multiset <int>::iterator iter;
    int n;

    cin >> n;
    
    for(int i=0;i<n;i++){
        int cmd;

        cin >> cmd;

        if(cmd == 0){
            if(heap.size() == 0) cout << 0 << "\n";
            else {
                iter = heap.begin();
                cout << *iter << "\n";
                heap.erase(iter);
            }
        }
        else {
            heap.insert(cmd);
        }
    }
}
// Baekjoon 15649
// 백트래킹
// 문제
// N과 M

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;
void tracking_function(deque <int> &que, int full_size,int end_val);

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;

    cin >> n >> m;
    
    for(int i=1;i<=n;i++){
        deque <int> que;
        que.push_back(i);

        tracking_function(que,m,n);
        que.clear();
    }

}

void tracking_function(deque <int> &que, int full_size,int end_val)
{
    if(que.size() == full_size){
        deque <int>::iterator iter;
        
        for(iter = que.begin();iter != que.end();iter++){
            cout << *iter << " ";
        }
        cout << "\n";
    }
    else {
        for(int i=1;i<=end_val;i++){
            if(find(que.begin(),que.end(),i) == que.end()){
                que.push_back(i);
                tracking_function(que,full_size,end_val);
                que.pop_back();
            }
            else continue;
        }
    }
}

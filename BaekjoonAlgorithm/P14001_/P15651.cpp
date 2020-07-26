// Baekjoon 15651
// 문제
// 백트래킹
// N과 M(3)

#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;
void backtracking_function(deque <int> &container,int full_size,int end_val);

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;

    cin >> n >> m;

    for(int i=1;i<=n;i++){
        deque <int> container;
        container.push_back(i);

        backtracking_function(container,m,n);

        container.clear();
    }
}

void backtracking_function(deque <int> &container,int full_size,int end_val)
{
    if(container.size() == full_size){
        deque <int>::iterator iter;
        for(iter = container.begin();iter != container.end();iter++){
            cout << *iter << " ";
        }
        cout << "\n";
    }
    else {
        for(int i=1;i<=end_val;i++){
            container.push_back(i);
            backtracking_function(container,full_size,end_val);
            container.pop_back();
        }
    }
}
// Baekjoon 6603
// 문제
// 백트래킹
// 로또

#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;
void backtracking_function(deque <int>&container , deque <int>&print_container);

int main()
{
    // ios_base :: sync_with_stdio(false);
    // cin.tie(NULL);
    
    while(1){
        int n;
        deque <int> container;
        deque <int> print_container;
        cin >> n;

        if(n == 0) break;
        else {
            for(int i=0;i<n;i++){
                int temp;

                cin >> temp;
                container.push_back(temp);
            }

            sort(container.begin(),container.end());

            for(int i=0;i<=container.size()-6;i++){
                print_container.push_back(container[i]);
                backtracking_function(container,print_container);
                print_container.clear();
            }
            cout << "\n";
        }
    }
}

void backtracking_function(deque <int>&container , deque <int>&print_container)
{
    if(print_container.size() == 6){
        deque <int>::iterator iter;

        for(iter = print_container.begin();iter != print_container.end();iter++){
            cout << *iter << " ";
        }
        cout << "\n";
    }
    else {
        int index = find(container.begin(),container.end(),print_container.back()) - container.begin() + 1;
        for(int i=index;i<container.size();i++){
            print_container.push_back(container[i]);
            backtracking_function(container, print_container);
            print_container.pop_back();
        }
    }
}
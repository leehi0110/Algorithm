// Baekjoon 10828
// 문제
// 스택

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    // ios_base :: sync_with_stdio(false);
    // cin.tie(NULL);
    
    int n;
    int val;
    string cmd;

    cin >> n;

    vector <int> stack;

    for(int i=0;i<n;i++){
        cin >> cmd;

        if(cmd == "push"){
            cin >> val;
            stack.push_back(val);
        }
        else if(cmd == "pop"){
            if(stack.size() == 0){
                cout << -1 << endl;
            }
            else {
                cout << stack.back() << endl;
                stack.pop_back();
            }
        }
        else if(cmd == "size"){
            cout << stack.size() << endl;
        }
        else if(cmd == "empty"){
            if(stack.size() == 0) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else if(cmd == "top"){
            if(stack.size() == 0){
                cout << -1 << endl;
            }
            else {
                cout << stack.back() << endl;
            }
        }
    }
}
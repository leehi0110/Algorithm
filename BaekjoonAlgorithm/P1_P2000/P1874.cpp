// Baekjoon 1874
// 문제
// 스택 수열

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    int index = 0;
    int value = 1;
    stack <int> Sequence_stack;
    vector <int> result;
    vector <char> oper; 

    cin >> n;
    vector <int> target(n);

    for(int i=0;i<n;i++){
        cin >> target[i];
    }

    while(1){
        if(Sequence_stack.empty()){
            Sequence_stack.push(value);
            oper.push_back('+');
            value++;
        }
        else {
            if(Sequence_stack.top() < target[index]){
                Sequence_stack.push(value);
                oper.push_back('+');
                value++;
            }
            else if(Sequence_stack.top() == target[index]){
                Sequence_stack.pop();
                oper.push_back('-');
                index++;
            }
            else {
                break;
            }
        }

        if(index == target.size()) break;
    }

    if(index != target.size()){
        cout << "NO" << endl;
    }
    else {
        for(char c : oper){
            cout << c << "\n";
        }
    }
}
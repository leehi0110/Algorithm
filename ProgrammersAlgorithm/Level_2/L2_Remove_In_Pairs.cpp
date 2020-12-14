#include <iostream>
#include<string>
#include<stack> // check
using namespace std;

int solution(string s)
{
    stack<char> Stack;

    for(int i =0;i<s.length();i++){
        if(Stack.empty())
            Stack.push(s[i]);
        else{
            if(Stack.top() == s[i]){
                Stack.pop();
            }
            else{
                Stack.push(s[i]);
            }
        }
    }
    if(Stack.empty())
        return 1;
    else 
        return 0;    
}
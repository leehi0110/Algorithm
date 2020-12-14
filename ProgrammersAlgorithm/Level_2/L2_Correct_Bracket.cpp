#include<string>
#include <iostream>
#include <deque>

using namespace std;

bool solution(string s)
{
    deque <char> st;

    if(s.length()%2 != 0) return false;
    else {
        for(int i=0;i<s.length();i++){
            if(s[i] == '(') st.push_back('(');
            else {
                if(st.empty()) return false;
                else {
                    st.pop_back();
                }
            }
        }
        if(st.empty()) return true;
        else return false;
    }
}
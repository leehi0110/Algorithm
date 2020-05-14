// Baekjoon 9012
// 문제
// 괄호

#include <iostream>
#include <vector>
#include <string>

using namespace std;
bool is_vps(string pair);

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int test_case;
    string pair;

    cin >> test_case;

    for(int i=0;i<test_case;i++){
        cin >> pair;

        if(is_vps(pair)) cout << "YES" <<endl;
        else cout << "NO" << endl;
    }   
}

bool is_vps(string pair)
{
    char now;
    vector <char> stack;

    for(int i=0;i<pair.length();i++){
        
        if(pair[i] == ')'){
            if(stack.size() == 0 ) {
                return false;
            }
            else if(stack.back() == '('){
                stack.pop_back();
            }
            else return false;
        }
        else { // pair[i] == '('
            stack.push_back(pair[i]);
        }
    }

    if(stack.size() == 0){
        return true;
    }
    else return false;
}
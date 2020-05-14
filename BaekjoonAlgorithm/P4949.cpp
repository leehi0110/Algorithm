// Baekjoon 4949
// 문제
// 균형잡힌 세상

#include <iostream>
#include <vector>
#include <string>

using namespace std;
bool check_balance(string check);

int main()
{
    // ios_base :: sync_with_stdio(false);
    // cin.tie(NULL);
    
    string check;

    while(1){
        getline(cin,check);
        
        if(check == "."){
            break;
        }
        else {
            if(check_balance(check) == true) cout << "yes" << endl;
            else cout << "no" << endl;
        }
    }
}

bool check_balance(string check)
{
    char pop_val;
    vector <char> pair;

    for(int i=0;i<check.length();i++){
        if(check[i] == '('){
            pair.push_back(check[i]);
        }
        else if(check[i] == ')'){
            if(pair.size() == 0){
                return false;
            }
            else if(pair.back() == '('){
                pair.pop_back();
            }
            else {
                return false;
            }
        }
        else if(check[i] == '['){
            pair.push_back(check[i]);
        }
        else if(check[i] == ']'){
            if(pair.size() == 0){
                return false;
            }
            else if(pair.back() == '['){
                pair.pop_back();
            }
            else {
                return false;
            }            
        }
        else continue;
    }

    if(pair.size() == 0) return true;
    else return false;
}
// Baekjoon 1541
// 문제
// 잃어버린 괄호

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    string input;
    string tmp = "";
    vector <char> oper;
    vector <string> number;
    
    cin >> input;

    oper.push_back('+');
    for(int i=0;i<input.length();i++){

        if(input[i] == '-' || input[i] == '+'){
            number.push_back(tmp);
            oper.push_back(input[i]);

            tmp = "";
        }
        else {
            tmp += input[i];
        }
    }
    number.push_back(tmp);
    
    for(int i=0;i<oper.size()-1;i++){
        if(oper[i] == '+'){
            if(oper[i+1] == '-') continue;
            else { // oper[i+1] == '+'
                number[i] = to_string(stoi(number[i]) + stoi(number[i+1]));
                oper.erase(oper.begin()+i+1);
                number.erase(number.begin()+i+1);
                i--;
            }
        }
        else { // oper[i] = '-'
            number[i] = to_string(stoi(number[i]) + stoi(number[i+1]));
            oper.erase(oper.begin()+i+1);
            number.erase(number.begin()+i+1);
            i--;
        }
    }

    if(number.size() == 1) cout << stoi(oper[0] + number[0]);
    else {
        string first = oper[0] + number[0];
        string second = oper[1] + number[1];

        cout << stoi(first) + stoi(second) << endl;
    }

}
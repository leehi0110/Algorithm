// Baekjoon 10610
// 문제
// 30

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    string n;
    int max_number, min_number;
    int min_mul;
    int result = -1;
    multiset <int> number_ele;
    multiset <int>::iterator iter;

    cin >> n;

    max_number = pow(10,n.length())-1;
    min_number = pow(10,n.length()-1); // 찾아야 하는 수의 범위

    for(int i=max_number;i>=min_number;i--){
        if(i%30 == 0) {
            min_mul = i;
            break;
        }
    }

    for(int i=0;i<n.length();i++){
        number_ele.insert(n[i] - '0');
    }

    for(min_mul;min_mul >= min_number;min_mul -= 30){
        multiset <int> oper_ele;
        string temp = to_string(min_mul);

        for(int i=0;i<temp.length();i++){
            oper_ele.insert(temp[i] - '0');
        }

        if(oper_ele == number_ele){
            result = min_mul;
            break;
        }
    }
    cout << result << endl;
}
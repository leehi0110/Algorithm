// Baekjoon 10610
// 문제
// 30

#include <iostream>
#include <vector>
<<<<<<< Updated upstream
#include <set>
#include <string>
#include <algorithm>
#include <cmath>
=======
#include <string>
#include <cmath>
#include <algorithm>
>>>>>>> Stashed changes

using namespace std;

int main()
{
<<<<<<< Updated upstream
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
=======
    string n;
    string max_temp = "";
    vector <int> number_ele;
    int result = -1;
    int max_number = -1;

    cin >> n;

    for(int i=0;i<n.length();i++){
        max_temp += "1";
        number_ele.push_back(n[i]- '0');
    }

    sort(number_ele.begin(),number_ele.end(),greater<int>());

    for(int i=stoi(max_temp)*9;i>=pow(10,n.length()-1);i--){
        if(i%30 == 0) {
            max_number = i;
>>>>>>> Stashed changes
            break;
        }
    }

<<<<<<< Updated upstream
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
=======
    for(int i=max_number;i>=pow(10,n.length()-1);i-=30){
        vector <int> sub_ele;
        int tmp = i;
        while(1){
            if(tmp < 10) {
                sub_ele.push_back(tmp);
                break;
            }
            else {
                sub_ele.push_back(tmp%10);
                tmp /= 10;
            }
        }
        sort(sub_ele.begin(),sub_ele.end(),greater<int>());

        if(sub_ele == number_ele) {
            result = i;
            break;
        }
    } // 30의 배수일 때
    cout << result;
>>>>>>> Stashed changes
}
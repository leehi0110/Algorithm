#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(string numbers) {
    int answer = 0;
    string tmp = numbers;

    sort(tmp.begin(),tmp.end(),greater<char>());
    int max_val = stoi(tmp);

    vector <bool> prime(max_val+1,true);
    vector <int> num(10,0);

    prime[0] = false;
    prime[1] = false;

    for(int i=2;i<prime.size();i++){
        if(prime[i] == true){
            for(int j=i*2;j<prime.size();j += i){
                prime[j] = false;
            }
        }
    } // 에라스토테네스의 체

    for(int i=0;i<numbers.length();i++){
        num[numbers[i] - '0'] ++;
    }

    for(int i=2;i<prime.size();i++){
        if(prime[i]){
            string s = to_string(i);

            for(int j=0;j<s.length();j++){
                if(count(s.begin(),s.end(),s[j]) > num[s[j] - '0']) break;

                if(j+1 == s.length()) answer ++;
            }
        }
    }

    return answer;
}

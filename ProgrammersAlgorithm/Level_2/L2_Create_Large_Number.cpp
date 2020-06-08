#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    deque<int> que;
    int returnLength = number.length() - k;

    for(int i=0;i<number.length();i++){
        que.push_back(number[i] - '0');
    }

    while(k != 0 && answer.length() != returnLength){
        int max = *max_element(que.begin(),que.begin()+k+1);
        int del = find(que.begin(),que.end(),max) - que.begin();

        answer += to_string(max);
        que.erase(que.begin(),que.begin()+del+1);

        k = k - del;
    }

    if(k == 0){
        for(int i : que){
            answer += to_string(i);
        }
    }

    return answer;
}
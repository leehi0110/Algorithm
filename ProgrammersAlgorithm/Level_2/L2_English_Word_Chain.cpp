#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<int> turn(n,0);
    int i;

    turn[0] ++;

    for(i=1;i<words.size();i++){
        turn[i%n] ++;

        if(words[i][0] != words[i-1][words[i-1].length()-1]){
            break;
        }
        else if(find(words.begin(),words.end(),words[i])-words.begin() != i){
            break;
        }
    }

    if(i == words.size()){
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back((i%n) + 1);
        answer.push_back(turn[i%n]);
    }

    return answer;
}
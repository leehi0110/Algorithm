#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;

    for(string i : strings){
        answer.push_back(i[n]+i);
    }

    sort(answer.begin(),answer.end());

    for(int i=0;i<answer.size();i++){
        answer[i].erase(0,1);
    }

    return answer;
}
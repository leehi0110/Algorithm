#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map <string,int> spy;
    map <string,int>::iterator iter;

    for(int i=0;i<clothes.size();i++){
        if(spy.find(clothes[i][1]) == spy.end()){
            spy.insert(pair<string,int>(clothes[i][1],1));
        }
        else {
            spy[clothes[i][1]]++;
        }
    }

    for(iter = spy.begin();iter != spy.end();iter++){
        answer *= (iter->second+1);
    }
    answer -= 1;

    return answer;
}

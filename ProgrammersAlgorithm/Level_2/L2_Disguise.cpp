#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    map <string,int> spy;
    map <string,int>::iterator start_iter;
    map <string,int>::iterator end_iter;
    map <string,int>::iterator iter;
    
    for(int i=0;i<clothes.size();i++){
        if(spy.find(clothes[i][1]) == spy.end()){
            spy.insert(pair<string,int>(clothes[i][1],1));
        }
        else {
            spy[clothes[i][1]] ++;
        }
        answer++; // 한가지만 착용하는 경우
    }
    
    // 두개 이상 착용하는 경우

    
    return answer;
}

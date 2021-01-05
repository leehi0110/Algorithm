#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    for(int i=0;i<progresses.size();i++){
        progresses[i] = 100 - progresses[i];

        if(progresses[i]%speeds[i] == 0) progresses[i] = progresses[i]/speeds[i];
        else progresses[i] = progresses[i]/speeds[i] + 1;
    }

    for(int i=0;i<progresses.size();i++){
        int cnt = 1;
        for(int j=i+1;j<progresses.size();j++){
            if(progresses[i] >= progresses[j]) cnt ++;
            else break;
        }
        answer.push_back(cnt);
        i += cnt-1;
        cnt = 1;
    }

    return answer;
}
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<double> rate;

    sort(stages.begin(),stages.end());

    for(int i=0;i<N;i++){
        int stagePerson = count(stages.begin(),stages.end(),i+1); // nowStage를 푸는 사람

        if(stages.size() == 0){
            for(int j=0;j<N-i;j++){
                rate.push_back(0);
            }
            break;
        }
        else {
            rate.push_back(static_cast<double>(stagePerson)/static_cast<double>(stages.size()));
            stages.erase(stages.begin(),stages.begin()+stagePerson);   
        }
    }

    for(int i=0;i<N;i++){
        double max = *max_element(rate.begin(),rate.end());
        int index = find(rate.begin(),rate.end(),max) - rate.begin();

        answer.push_back(index+1);
        rate[index] = -1;
    }

    return answer;
}
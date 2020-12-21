#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector <double> fail;
    
    sort(stages.begin(),stages.end());
    
    for(int i=1;i<=N;i++) {
        int stayUser = count(stages.begin(),stages.end(),i);
        int wholeUser = stages.size();
        
        if(stayUser == 0) fail.push_back(0.0);
        else {
            fail.push_back((double)stayUser/wholeUser);
            stages.erase(stages.begin(),stages.begin()+stayUser);
        }
    }
    
    for(int i=0;i<fail.size();i++) {
        int maxIndex = max_element(fail.begin(),fail.end()) - fail.begin();
        answer.push_back(maxIndex+1);
        
        fail[maxIndex] = -1;
    }
    
    return answer;
}
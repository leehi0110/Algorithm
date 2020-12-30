#include <string>
#include <vector>
#include <map>
#include <utility>
// #include <numeric>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string,int> category;
    map<string,int>::iterator iter;
    vector<int> cnt;
    
    for(int i=0;i<clothes.size();i++) {
      iter = category.find(clothes[i][1]);

      if(iter == category.end()) category.insert(pair<string,int>(clothes[i][1],1));
      else iter->second++;
    }

    for(iter=category.begin();iter != category.end();iter++) {
      answer *= (iter->second + 1);
    }
    
    answer--;

    return answer;
}
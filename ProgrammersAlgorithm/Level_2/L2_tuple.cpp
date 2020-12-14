#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map <int,int> element;
    string tmp = "";
    int i;

    for(i=0;i<s.length();i++){
        if(isdigit(s[i])) tmp += s[i];
        else if(!isdigit(s[i]) && tmp.length() != 0){
            if(element.find(stoi(tmp)) == element.end()){
                element.insert(pair<int,int>(stoi(tmp),1));
            }
            else {
                element[stoi(tmp)]++;
            }
            tmp = "";
        }
    }

    map <int,int>::iterator iter;
    vector <pair<int,int>> numbers(element.size());

    for(iter = element.begin(),i=0; iter != element.end();iter++,i++){
        numbers[i].first = iter->second;
        numbers[i].second = iter->first;
    }

    sort(numbers.begin(),numbers.end());
    for(i=numbers.size()-1;i > -1 ;i--){
        answer.push_back(numbers[i].second);
    }


    return answer;
}
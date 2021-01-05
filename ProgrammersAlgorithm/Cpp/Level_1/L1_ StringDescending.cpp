#include <string>
#include <vector>
#include<algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<char> v;
    for(int i =0; i<s.length(); i++){
        v.push_back(s[i]);
    }
    sort(v.begin(), v.end());
    for(int i =v.size()-1; i>=0; i--){
        answer += v[i];
    }

    return answer;
}

// sort (begin,end,compare)
// sort (begin, end, greater<자료형>()) => 내림차순
// sort (begin, end, less<자료형>()) => 오름차순
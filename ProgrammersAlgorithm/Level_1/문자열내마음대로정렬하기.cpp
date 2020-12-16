// ProblemNumber || ProblemName : 문자열 내 마음대로 정렬하기
// 문제
// 문자열의 n번째 문자를 기준으로 배열에 있는 문자열을 정렬하시오

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int index;

bool compare(string a, string b){
    if(a[index] > b[index]) return false;
    else if(a[index] < b[index]) return true;
    else {
        if(a > b) return false;
        else return true;
    }
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    
    index = n;
    
    sort(strings.begin(),strings.end(),compare);
    
    return strings;
}

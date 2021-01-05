// ProblemNumber || ProblemName : 문자열 내림차순으로 정렬하기
// 문제
// 문자열을 내림차순으로 정렬하시오

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    
    string big = "";
    string small = "";
    
    for(int i=0;i<s.length();i++){
        if(s[i] >= 'a' && s[i] <= 'z') small.push_back(s[i]);
        else big.push_back(s[i]);
    }
    
    sort(small.begin(),small.end(),greater<char>());
    sort(big.begin(),big.end(),greater<char>());
    
    return small+big;
    
}

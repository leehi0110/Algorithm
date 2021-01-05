// ProblemNumber || ProblemName : 전화번호 목록
// 문제
// 한 전화번호가 특정 다른 전화번호의 접두사로 쓰였는지 체크하시오

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(),phone_book.end());
    
    for(int i=0;i<phone_book.size()-1;i++) {
        string tmp = phone_book[i+1].substr(0,phone_book[i].size());
        if(tmp == phone_book[i]) return false;
    }
    return answer;
}

// ProblemNumber || ProblemName : 서울에서 김서방 찾기
// 문제
// 배열에서 "Kim"의 위치를 찾아 문자열로 반환하시오

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    
    int index = find(seoul.begin(),seoul.end(),"Kim") - seoul.begin();
    return "김서방은 "+to_string(index)+"에 있다";
}

// ProblemNumber || ProblemName : 핸드폰 번호 가리기
// 문제
// 핸드폰 마지막 4자리를 제외하고 *로 가리시오

#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    
    for(int i=phone_number.size()-5;i>-1;i--){
        phone_number[i] = '*';
    }
    return phone_number;
}

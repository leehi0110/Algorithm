// ProblemNumber || ProblemName : 2016년
// 문제
// 2016년의 특정 날짜의 요일을 구하시오

#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    vector<string> day = {"THU", "FRI", "SAT","SUN","MON", "TUE", "WED",};
    vector<int> month_day = {31,29,31,30,31,30,31,31,30,31,30,31};
    
    int total_day=0;
    
    for(int i=0;i<a-1;i++){
        total_day += month_day[i];
    }
    total_day += b;
    
    answer = day[total_day%7];
    
    return answer;
}

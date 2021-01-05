// ProblemNumber || ProblemName : 큰 수 만들기
// 문제
// 어떤 숫자에서 k개의 수를 제거했을 때 얻을 수 있는 가장 큰 숫자를 구하라

#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int index = 0;
    
    if(number.length() == k) return "";
    
    for(int i=0;i<k;i++) {  
        for(int j=0;j<number.length()-1;j++) {
            if(number[j] < number[j+1]) {
                number.erase(number.begin()+j);
                break;
            }
            
            if(j == number.length()-2) number.erase(number.end()-1);
        }
    }
    
    return number;
}
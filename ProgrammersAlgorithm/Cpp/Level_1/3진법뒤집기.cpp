// ProblemNumber || ProblemName : 3진법 뒤집기
// 문제
// 10진수를 3진법 전환한 뒤 뒤집어 다시 10진법으로 변환하시오

#include <iostream>
#include <string>

using namespace std;

#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <typeinfo>

using namespace std;

int solution(int n) {
    int answer = 0;
    string dec = "";
    bool first = false;
    
    for(int i=16;i>-1;i--) {
        if(n == 0) {
            for(int j=i;j>-1;j--) {
                dec += "0";
            }
            break;
        }
        
        for(int j=2;j>-1;j--) {
            int result = pow(3,i) * (j+1);
            
            if(n >= result) {
                n -= result;
                
                dec += to_string(j+1);
                first = true;
                break;
            }
            
            if(j == 0) {
                dec += "0";
            }
        }
    }
    
    int lastZero;
    
    for(int i=0;i<dec.length();i++) {
        if(dec[i] == '0') continue;
        else {
            lastZero = i;
            break;
        }
    }
    
    dec = dec.substr(lastZero,dec.length()-lastZero+1);
    
    for(int i=0;i<dec.length();i++){
        if(dec[i] == '0') continue;
        else {
            answer += pow(3,i)*(dec[i] - '0');
        }
    }
    
    return answer;
}
// ProblemNumber || ProblemName : 소수 찾기
// 문제
// 1 ~ n 사이의 소수의 개수를 반환하시오.

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector <bool> arr(n+1,true);
    
    for(int i=2;i<n+1;i++){
        if(arr[i] == true) {
            for(int j=i+i;j<n+1;j+=i){
                arr[j] = false;
            }
        }
    }
    
    for(int i=2;i<n+1;i++) {
        if(arr[i]) answer ++;
    }
    
    return answer;
}
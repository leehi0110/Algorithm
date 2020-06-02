#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;

    vector<bool> vec(n+1,true);

    for(int i=2;i<=n;i++){
        if(vec[i] == true){
            for(int j=i*2;j<=n;j += i){
                vec[j] = false;
            }
            answer ++;
        }
    }

    return answer;
}
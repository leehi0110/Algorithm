#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = 0;
    int i,j;
    int minLen = s.length();

    for(i=1;i<s.length()/2+1;i++){

        int cnt = 1;
        string sub = "";

        for(j=0;j<s.length()-i;j+=i){
            if(s.substr(j,i) == s.substr(j+i,i)){
                cnt ++;
            }
            else {
                if(cnt > 1) {
                    sub += to_string(cnt);
                }
                sub += s.substr(j,i);
                cnt = 1;
            }
        }

        if(cnt > 1){
            sub += to_string(cnt);
        }

        for(int k=j;k<s.length();k++){
            sub += s[k];
        }
        if(minLen > sub.length()) minLen = sub.length();
    }

    return minLen;
}
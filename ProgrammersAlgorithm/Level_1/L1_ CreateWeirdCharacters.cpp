#include <string>
#include <vector>
#include <iostream>
#include <cctype>

using namespace std;

string solution(string s) {
    int flag = 0;

    for(int i=0;i<s.length();i++){
        if(s[i] == ' ') {
            flag = 0;
        }
        else if((flag+2)%2 == 0){
            s[i] = toupper(s[i]);
            flag ++;
        }
        else {
            s[i] = tolower(s[i]);
            flag ++;
        }
    }
    return s;
}

// #include <cctype>
// tolower & toupper 사용가능

// #include <sstream>
// istringStream alias(string)
// getline(string, bufferString, delim)
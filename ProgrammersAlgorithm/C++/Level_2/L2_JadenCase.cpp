#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    bool first = true;
//     stringstream str(s);
//     string buffer;

//     while(!str.eof()){
//         str >> buffer;

//         std::transform(buffer.begin(),buffer.end(),buffer.begin(),::tolower);
//         buffer[0] = toupper(buffer[0]);
//         answer += buffer;

//         if(!str.eof()) answer += " ";
//     }

    for(int i=0;i<s.length();i++){
        if(s[i] == ' ') {
            first = true;
            answer += s[i];
        }
        else {
            if(first){
                s[i] = toupper(s[i]);
                answer += s[i];
                first = false;
            }
            else {
                s[i] = tolower(s[i]);
                answer += s[i];
            }
        }
    }

    return answer;
}
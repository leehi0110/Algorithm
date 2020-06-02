#include <string>
#include <vector>
#include <iostream>

using namespace std;

// Solution 2)
string solution(string s, int n) {
    string answer = "";
    int tmp;
    
    for(int i=0;i<s.length();i++){
        if(s[i] == ' ') answer += s[i];
        else {
            tmp = s[i] >= 'a' ? 'a' : 'A';
            
            answer += static_cast<char>(tmp + ((s[i] - tmp + n)%26));
        }
    }
    
    return answer;
}

// Solution 1)
// string solution(string s, int n) {
//     string answer = "";
//     int tmp;

//     for(int i=0;i<s.length();i++){
//         if(s[i] == ' ') answer += s[i];
//         else {
//             tmp = static_cast<int>(s[i]) + n;

//             if(s[i] >= 'A' && s[i] <= 'Z'){

//                 if(tmp > 90){
//                     tmp = tmp%90 + 64;
//                 }

//             }
//             else {
//                 if(tmp > 122){
//                     tmp = tmp%122 + 96;
//                 }

//             }

//             answer += static_cast<char>(tmp);
//         }
//     }

//     return answer;
// }
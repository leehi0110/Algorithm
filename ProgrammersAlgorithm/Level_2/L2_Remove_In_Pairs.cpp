#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int solution(string s)
{
    int original;
    int deleteLen = s.length();
    
    do {
        original = deleteLen;
        
        cout << "before s = " << s << endl;
        
        for(int i=0;i<s.length()-1;i++){
            if(s[i] == s[i+1]){
                s.erase(s.begin()+i,s.begin()+i+2);
                cout << "after s = " << s << endl;        
                i--;
            }

            if(s == "") break;
        }
        
        if(s == "") break;
        
        cout << "after after s = " << s << endl;
        deleteLen = s.length();
        
    } while( deleteLen != original || deleteLen == 0);
    
    return s == "" ? 1 : 0;
}

int main()
{
    cout << solution("baabaa") << endl;
    cout << solution("cdcd") << endl;
}

//         for(int i=0;i<s.length()-1;i++){
//             if(s[i] == s[i+1]) {
//                 s.erase(s.begin()+i,s.begin()+i+2);
//                 i = -1;
//             }
            
//             if(i == s.length()-1) break;
//         }
    
//     return s == "" ? 1 : 0;
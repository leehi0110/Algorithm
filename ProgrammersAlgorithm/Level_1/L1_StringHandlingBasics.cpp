#include <string>
#include <vector>

using namespace std;

bool solution(string s) {

    if(s.length() == 4 || s.length() == 6){
        for(int i=0;i<s.length();i++){
            if(s[i] >= 'a' && s[i] <= 'z') return false;
        }
        return true;
    }
    else return false;
}

// #include <cctype>

// isdigit('<char>문자') => return 0
// isdigit('<char>숫자') => return !0
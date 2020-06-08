#include <string>
#include <vector>

using namespace std;

string solution(int n) {

    string answer = "";

    while(1){

        if((n-1)/3 > 0){
            if((n-1)%3 == 0) answer = "1" + answer;
            else if((n-1)%3 == 1) answer = "2" + answer;
            else answer = "4" + answer;

            n = (n-1)/3;
        }
        else {
            if(n == 1) answer = "1" + answer;
            else if(n == 2) answer = "2" + answer;
            else answer = "4" + answer;

            break;
        }
    }

    return answer;
}
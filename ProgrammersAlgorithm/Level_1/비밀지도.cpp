// ProblemNumber || ProblemName : 비밀지도
// 문제
// 배열을 비교하여 하나의 지도로 만드시오

#include <string>
#include <vector>
#include <cmath>

using namespace std;
string changeBinary(int size, int num);

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i=0;i<arr1.size();i++) {
        string temp = "";
        string binaryA = changeBinary(n-1,arr1[i]);
        string binaryB = changeBinary(n-1,arr2[i]);
        
        for(int j=0;j<n;j++) {
            if(binaryA[j]-'0' | binaryB[j]-'0') temp += "#";
            else temp += " ";
        }
        answer.push_back(temp);
    }
    
    return answer;
}

string changeBinary(int size, int num) {
    string result = "";
    
    for(int i=size;i>=0;i--) {
        if(pow(2,i) <= num) {
            result += "1";
            num -= pow(2,i);
        }
        else result += "0";
    }
    
    return result;
}
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
bool sort_dic(int a, int b);

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(),numbers.end(),sort_dic);
    
    for(int i : numbers){
        answer += to_string(i);
    }
    
    if(answer[0] == '0') return "0";
    else return answer;
}

bool sort_dic(int a, int b){
    return to_string(a)+to_string(b) > to_string(b) + to_string(a);
}
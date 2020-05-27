#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    int target = 4;
    
    int month[] = {31,29,31,30,31,30,31,31,30,31,30,31};
    string date[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    
    for(int i=0;i<a-1;i++){
        target += month[i];
    }
    
    return date[(target+b)%7];
}
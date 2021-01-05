#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(int x) {
    int sum = 0;
    string str = to_string(x);

    for(int i=0;i<str.length();i++){
        sum += str[i] - '0';
    }

    return x%sum == 0 ? true : false;
    // return x%sum == 0; <= 간결

}
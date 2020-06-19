#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    string buffer;
    int num;
    int min;
    int max;

    stringstream str(s);

    str >> buffer;
    num = stoi(buffer);

    max = num;
    min = num;

    while(!str.eof()){

        str >> buffer;
        num = stoi(buffer);

        if(num > max) max = num;
        if(num < min) min = num;

    }
    return to_string(min) + " " + to_string(max);
}
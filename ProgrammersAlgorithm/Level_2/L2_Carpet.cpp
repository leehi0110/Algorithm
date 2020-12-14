#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int width = yellow , height = 1;

    while((width+height)*2 != brown-4 || width*height != yellow){
        height ++;
        width = yellow/height;
    }

    answer.push_back(width+2);
    answer.push_back(height+2);

    return answer;
}
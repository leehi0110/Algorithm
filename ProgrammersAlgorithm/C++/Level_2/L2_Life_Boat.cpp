#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int start = 0;
    int end = people.size()-1;

    sort(people.begin(),people.end());

    while(start < end){
        if(people[start] + people[end] <= limit){
            answer ++;
            start++;
            end --;
        }
        else {
            answer ++;
            end --;
        }

        if(start == end) {
            answer ++;
            break;
        }
    }

    return answer;
}
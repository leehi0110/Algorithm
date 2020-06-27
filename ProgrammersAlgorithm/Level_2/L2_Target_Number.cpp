#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int recur_target(vector<int> &numbers,int index,int now_sum,int target);

int solution(vector<int> numbers, int target) {
    int answer = 0;

    answer = recur_target(numbers,0,0,target);

    return answer;
}

int recur_target(vector<int> &numbers,int index,int now_sum,int target)
{
    if(numbers.size() == index) {
        if(now_sum == target) return 1;
        else return 0;
    }
    else {
        return recur_target(numbers,index+1,now_sum+numbers[index],target) + 
        recur_target(numbers,index+1,now_sum-numbers[index],target);
    }

}
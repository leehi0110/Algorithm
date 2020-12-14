#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    multiset <int> arr;
    multiset <int>::iterator iter;

    for(int i : scoville){
        arr.insert(i);
    }

    while(*(arr.begin()) < K){
        int first, second;

        iter = arr.begin();

        first = *iter;
        iter ++;
        second = *iter;
        iter ++;

        arr.erase(arr.begin(),iter);
        arr.insert(first + (2*second));
        answer ++;

        if(arr.size() == 1 && *(arr.begin()) < K) {
            return -1;
        }
    }

    return answer;
}
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int citation_cnt(vector <int> &vec , int n);

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(),citations.end(),greater<int>());

    while(1){
        if(citation_cnt(citations,answer) >= answer) answer++;
        else return answer-1;
    }

}

int citation_cnt(vector <int> &vec , int n)
{
    int cnt = 0;

    for(int i : vec){
        if(i >= n) cnt++;
        else break;
    }

    return cnt;
}
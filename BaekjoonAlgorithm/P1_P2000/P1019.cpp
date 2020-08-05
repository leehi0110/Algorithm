// Baekjoon 1019
// 문제
// 탐색
// 책 페이지

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n;

    cin >> n;

    map <int,int> number_cnt;
    map <int,int>::iterator iter;

    for(int i=0;i<10;i++){
        number_cnt.insert(pair<int,int>(i,0));
    }

    for(int i=0;i<n;i++){
        
    }
}
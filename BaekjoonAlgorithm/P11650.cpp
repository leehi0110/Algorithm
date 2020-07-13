// Baekjoon 11650
// 문제
// 좌표 정렬하기

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    cin >> n;
    map <int,vector<int>> number;
    
    for(int i=0;i<n;i++){
        int x ,y;

        cin >> x >> y;

        if(number.find(x) == number.end()){
            number.insert(pair<int,vector<int>>(x,{y}));
        }
        else {
            number[x].push_back(y);
        }
    }

    map <int,vector<int>>::iterator iter;

    for(iter = number.begin();iter != number.end();iter++){
        sort(iter->second.begin(),iter->second.end());
        for(int i=0;i<iter->second.size();i++){
            cout << iter->first << " " << iter->second[i] << "\n";
        }
    }
}
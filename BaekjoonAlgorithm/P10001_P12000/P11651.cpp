// Baekjoon 11651
// 문제
// 좌표 정렬하기 2

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    map <int,vector<int>> number;

    cin >> n;

    while(n--){
        int x , y;

        cin >> x >> y;

        if(number.find(y) == number.end()){
            number.insert(pair<int,vector<int>>(y,{x}));
        }
        else {
            number[y].push_back(x);
        }
    }

    map <int,vector<int>>::iterator iter;

    for(iter = number.begin();iter != number.end();iter++){
        sort(iter->second.begin(),iter->second.end());
        for(int i=0;i<iter->second.size();i++){
            cout << iter->second[i] << " " << iter->first << "\n";
        }
    }

}
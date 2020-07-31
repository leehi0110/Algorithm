// Baekjoon 11656
// 문제
// 문자열 처리
// 접미사 배열

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    string target;
    vector <string> target_vector;

    cin >> target;

    while(target.length()){
        target_vector.push_back(target);
        target.erase(target.begin());
    }

    sort(target_vector.begin(),target_vector.end());

    for(string s : target_vector){
        cout << s << "\n";
    }
}
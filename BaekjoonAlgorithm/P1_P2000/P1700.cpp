// Baekjoon 1700
// 문제
// 그리디
// 멀티탭 스케줄링

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    int answer = 0;

    cin >> n >> k;

    vector <int> tap_vector;

    for(int i=0;i<k;i++){
        int temp;
        cin >> temp;
        if(find(tap_vector.begin(),tap_vector.end(),temp) == tap_vector.end()){
            if(tap_vector.size() == n){
                tap_vector.erase(tap_vector.begin());
                answer ++;
            }
            tap_vector.push_back(temp);
            sort(tap_vector.begin(),tap_vector.end(),greater<int>());
        }
    }
    cout << answer << endl;
}
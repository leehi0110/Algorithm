// Baekjoon 2108
// 문제
// 통계학

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int sum = 0;
    bool mid_flag = false;
    bool frequecy_flag = false;
    int now_cnt = -1;
    int max_frequency_cnt = 0;
    int max_frequency_num, mid_num;
    map <int,int> number_map;

    cin >> n;

    for(int i=0;i<n;i++){
        int temp;

        cin >> temp;
        sum += temp;

        if(number_map.find(temp) == number_map.end()){
            number_map.insert(pair<int,int>(temp,1));
        }
        else {
            number_map[temp]++;
        }
    }
    cout << round(static_cast<double>(sum)/static_cast<double>(n)) << endl; // 산술평균

    map <int,int>::iterator start_iter = number_map.begin();

    for(;start_iter != number_map.end();start_iter++){
        now_cnt += start_iter->second;
        if(!mid_flag && now_cnt >= n/2) {
            cout << start_iter->first << endl; // 중앙값
            mid_flag = !mid_flag;
        }

        if(max_frequency_cnt < start_iter->second){
            max_frequency_cnt = start_iter->second;
            max_frequency_num = start_iter->first;
            frequecy_flag = false;
        }
        else if(max_frequency_cnt = start_iter->second){
            if(!frequecy_flag){
                max_frequency_num = start_iter->first;
                frequecy_flag = !frequecy_flag;
            }
        }
    }

    cout << max_frequency_num << endl;
    cout << number_map.rbegin()->first - number_map.begin()->first << endl;

}
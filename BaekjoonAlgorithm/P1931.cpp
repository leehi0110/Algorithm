// Baekjoon 1931
// 문제
// 회의실 배정

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
int check_conference_cnt(int start_time,multimap<int,int> &time_table,multimap<int,int>::iterator &iter);

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int conference_num;
    int max_conference = 0;

    multimap <int,int> time_table;
    multimap <int,int>::iterator iter;

    cin >> conference_num;

    for(int i=0;i<conference_num;i++){
        int start_time, end_time;

        cin >> start_time >> end_time;
        time_table.insert(pair<int,int>(start_time,end_time));
    }

    for(iter = time_table.begin();iter != time_table.end();iter++){
        int count_conference = 1;

        count_conference += check_conference_cnt(iter->second,time_table,iter);
        if(max_conference < count_conference) max_conference = count_conference;
    }
    cout << max_conference;
}

int check_conference_cnt(int start_time,multimap<int,int> &time_table,multimap<int,int>::iterator &iter)
{
    int recur_max_cnt = 0;
    int tmp_cnt;

    for(iter;iter != time_table.end();iter++){
        if(iter->first >= start_time) {
            tmp_cnt = 1 + check_conference_cnt(iter->second,time_table,iter);
        }
        if(tmp_cnt > recur_max_cnt) {
            return recur_max_cnt > tmp_cnt ? recur_max_cnt : tmp_cnt;
        }    
    }

    return recur_max_cnt;
}
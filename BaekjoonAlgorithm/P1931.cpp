// Baekjoon 1931
// 문제
// 회의실 배정

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
long long check_next_conference(int start_time,multimap <int,int> &time_table,multimap <int,int>::iterator &iter);

int main()
{
    long long conference_num;
    long long max_conference = 0;
    multimap <int, int> time_table;
    multimap <int,int>::iterator iter;

    cin >> conference_num;

    while(conference_num--){
        int start_time, end_time;

        cin >> start_time >> end_time;

        time_table.insert(pair<int,int>(start_time,end_time));
    }

    for(iter = time_table.begin();iter != time_table.end();iter++){
        cout << iter->first << " " << iter->second << endl;
    }

    for(iter = time_table.begin();iter != time_table.end();iter++){
        long long conference_num;

        conference_num = 1 + check_next_conference(iter->second,time_table,iter);
        if(max_conference < conference_num) max_conference = conference_num;
    }

    cout << max_conference << endl;
}

long long check_next_conference(int start_time,multimap <int,int> &time_table,multimap <int,int>::iterator &iter)
{
    multimap <int,int>::iterator start_iter = iter;
    long long max_conference = 0;

    start_iter++;
    for(;start_iter != time_table.end();start_iter++){
        long long conference_num = 0;
        if(start_iter->first >= start_time){
            conference_num = 1 + check_next_conference(start_iter->second,time_table,start_iter);
            if(max_conference < conference_num) max_conference = conference_num;
        }
    }
    
    return max_conference;
}

// Baekjoon 1931
// 문제
// 회의실 배정

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
int recur_conference(int start_time, multimap<int,int>::iterator &iter, multimap<int,int> &time_table);

int main()
{
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
        int check_conference = 1;
        check_conference += recur_conference(iter->second,iter,time_table);

        if(max_conference < check_conference) max_conference = check_conference;
    }

    cout << max_conference << endl;
}

int recur_conference(int start_time, multimap<int,int>::iterator &iter, multimap<int,int> &time_table)
{
    cout << " now start_time << " << start_time << endl;
    int check_conference = 0;
    for(iter;iter != time_table.end();iter++){
        if(iter->first >= start_time) {
            cout << "next start time = " << iter->first << endl;
            int tmp = 1 + recur_conference(iter->second,iter,time_table);
            if(check_conference > tmp) {
                check_conference = tmp;
            }
        }
        return check_conference;
    }
    return 0;
}
// Baekjoon 14501
// 문제
// 퇴사

#include <iostream>
#include <vector>
#include <string>

using namespace std;
int check_money(vector <pair<int,int>> &counsel, int start_day,int end_day,int last_day);

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int end_day;
    int last_day;
    int max_money = 0;

    cin >> end_day;
    last_day = end_day + 1;

    vector <pair<int,int>> counsel(end_day);

    for(int i=0;i<end_day;i++){
        cin >> counsel[i].first >> counsel[i].second;
    }

    for(int i=0;i<end_day;i++){

        int return_money;

        return_money = check_money(counsel,i,end_day,last_day);

        if(max_money < return_money) max_money = return_money;
    }

    cout << max_money << endl;

}

int check_money(vector <pair<int,int>> &counsel, int start_day,int end_day,int last_day)
{
    int max_money = 0;

    for(int i=start_day;i<end_day;i++){
        int find_money = 0;
        
        if(counsel[i].first+i+1 <= last_day) {
            find_money = counsel[i].second + check_money(counsel,counsel[i].first+i,end_day,last_day);
        }
        if(find_money > max_money) max_money = find_money;

    }
    return max_money;
}
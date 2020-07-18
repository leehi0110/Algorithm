// Baekjoon 2352
// 문제
// 그리디
// 반도체 설계

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int max_cnt = 0;

    cin >> n;

    vector <pair<int,int>> conductor;

    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;

        conductor.push_back(pair<int,int>(temp,i+1));
    }

    sort(conductor.begin(),conductor.end());

    for(int i=0;i<n;i++){
        int cnt = 1;
        int right = conductor[i].second;
        for(int j=i+1;j<n;j++){
            if(conductor[j].second > right){
                cnt ++;
                right = conductor[j].second;
            }
        }
        if(max_cnt < cnt) max_cnt = cnt;
    }

    cout << max_cnt << endl;
}

// int main()
// {
//     ios_base :: sync_with_stdio(false);
//     cin.tie(NULL);

//     int n;
//     int max_cnt = 0;

//     cin >> n;
//     vector <int> conductor(n);

//     for(int i=0;i<n;i++){
//         cin >> conductor[i];
//     }

//     for(int i=0;i<n;i++){
//         int left = i+1;
//         int right = conductor[i]+1;
//         int cnt = 1;

//         while(right <= n){
//             int index = find(conductor.begin(),conductor.end(),right) - conductor.begin();
//             if(index+1 > left){
//                 cnt++;
//                 left = index+1;
//             }
//             right ++;
//         }

//         if(cnt > max_cnt) max_cnt = cnt;
//     }

//     cout << max_cnt << endl;
// }
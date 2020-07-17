// Baekjoon 1138
// 문제
// 그리디
// 한 줄로 서기

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;

    cin >> n;

    vector <int> row(n);
    vector <int> result;

    for(int i=0;i<n;i++){
        cin >> row[i];
    }

    int index = find(row.begin(),row.end(),0) - row.begin();
    result.push_back(index+1);
    row[index] = row.size(); // 초기 가장 왼쪽에 대한 처리

    for(int i=0;i<row.size();i++){

        if(*(min_element(row.begin(),row.end())) == row.size()) break;
        else {
            if(result.size() < row[i]) continue;
            else {
                int cnt = 0;
                for(int j=0;j<result.size();j++){
                    if(result[j] > i+1) cnt++;
                }
                if(cnt == row[i]) {
                    result.push_back(i+1);
                    row[i] = row.size();
                    i = -1;
                }
            }
        }
    }

    for(int i : result){
        cout << i << " ";
    }
    cout << endl;
}

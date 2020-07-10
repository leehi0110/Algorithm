// Baekjoon 10989
// 문제
// 수 정렬하기 3

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    vector <int> arr(10000,0);

    int n;
    int cnt = 0;
    cin >> n;

    for(int i=0;i<n;i++){
        int val;
        cin >> val;
        arr[val-1]++;
    }

    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i];j++){
            cnt ++;
            cout << i+1 << "\n";
        }
        if(cnt == n) break;
    }

}
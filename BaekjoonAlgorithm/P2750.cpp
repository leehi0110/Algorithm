// Baekjoon 2750
// 문제
// 수 정렬하기

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
// bool desc(int a, int b);

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    
    cin >> n;

    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    sort(arr.begin(),arr.end());

    for(int i=0;i<arr.size();i++){
        cout << arr[i] << endl;
    }

}

// bool desc(int a, int b)
// {
//     return a > b;
// } 내림차순 정렬
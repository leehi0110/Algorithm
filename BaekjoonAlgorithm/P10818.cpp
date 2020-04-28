// Baekjoon 10818 
// 문제 
// 최소, 최대

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    // ios_base :: sync_with_stdio(false);
    // cin.tie(NULL);

    int n;
    int val;

    cin >> n;

    vector <int> array;

    for(int i=0;i<n;i++){
        cin >> val;
        array.push_back(val);
    }

    sort(array.begin(),array.end());

    cout << array[0] << " " << array[array.size()-1] << endl;
}
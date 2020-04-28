// Baekjoon 10870
// 문제
// 피보나치 수 5

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    // ios_base :: sync_with_stdio(false);
    // cin.tie(NULL);
 
    vector <int> array(21);

    int n;

    array[0] = 0;
    array[1] = 1;

    cin >> n;

    for(int i=2;i<array.size();i++){
        array[i] = array[i-1] + array[i-2];
    }

    // for(int i=0;i<array.size();i++){
    //     cout << "index = " << i << "value = " << array[i] << endl;
    // }

    cout << array[n] << endl;
}
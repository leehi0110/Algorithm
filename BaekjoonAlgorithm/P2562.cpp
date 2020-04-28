// Baekjoon 2562
// 문제
// 최댓값

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    // ios_base :: sync_with_stdio(false);
    // cin.tie(NULL);

    int max_val=0;
    int max_index;
    vector <int> array(9);

    for(int i=0;i<9;i++){
        cin >> array[i];
        if(array[i] > max_val){
            max_val = array[i];
            max_index = i+1;
        }
    }

    cout << max_val << " " << max_index << endl;
}
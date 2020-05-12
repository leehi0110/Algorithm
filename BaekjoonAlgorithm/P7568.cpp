// Baekjoon 7568
// 문제
// 덩치

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int person;
    int x,y;

    cin >> person;

    vector <vector <int>> arr(person, vector<int>(2,0));

    for(int i=0;i<person;i++){
        cin >> x >> y;
        arr[i][0] = x;
        arr[i][1] = y;
    }

    for(int i=0;i<person;i++){

        int rank = 0;

        for(int j=0;j<person;j++){
            if(i == j) rank ++;
            else {
                if(arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1]){
                    rank++;
                }
            }    
        }
        cout << rank << " ";
    }
}
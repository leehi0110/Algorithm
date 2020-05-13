// 2주차
// array-3

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    // ios_base :: sync_with_stdio(false);
    // cin.tie(NULL);
    
    int n;
    int val =1;

    cin >> n;

    vector <vector <int>> arr(n,vector<int>(n));

    for(int i=0;i<n;i++){
        if((i+2)%2 == 0){
            for(int j=0;j<n;j++){
                arr[i][j] = val;
                val ++;
            }
        }
        else {
            for(int j=n-1;j>-1;j--){
                arr[i][j] = val;
                val ++;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
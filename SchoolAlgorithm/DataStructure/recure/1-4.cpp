// 1주차
// recure-4

#include <iostream>
#include <vector>
#include <string>

using namespace std;
int recure_max(vector<int> &arr,int  n);

int main()
{
    // ios_base :: sync_with_stdio(false);
    // cin.tie(NULL);
    
    int n;
    int i;

    cin >> n;

    vector <int> arr(n);

    for(i=0;i<n;i++){
        cin >> arr[i];
    }

    cout << recure_max(arr,n) << endl;
    
}

int recure_max(vector<int> &arr,int  n){

    if(n == 0){
        return arr[0];
    }
    else return arr[n-1] > recure_max(arr,n-1) ? arr[n-1] : recure_max(arr,n-1);

}
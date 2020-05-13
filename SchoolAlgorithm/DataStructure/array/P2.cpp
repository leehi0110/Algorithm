// 2주차
// array-2

#include <iostream>
#include <vector>
#include <string>

using namespace std;
void changeVal(vector<int> &arr,int pivotIndex,int targetIndex);

int main()
{
    // ios_base :: sync_with_stdio(false);
    // cin.tie(NULL);
    
    int n,i,repeat;

    cin >> n;

    vector <int> arr(n);

    for(i=0;i<n;i++){
        cin >> arr[i];
    }

    cin >> repeat;

    vector <int> changeArr(repeat);
    for(i=0;i<repeat;i++){
        cin >> changeArr[i];
    }

    for(i=1;i<repeat;i++){
        changeVal(arr,changeArr[0],changeArr[i]);
    }

    for(i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void changeVal(vector<int> &arr,int pivotIndex,int targetIndex)
{
    int tmp;

    tmp = arr[pivotIndex];
    arr[pivotIndex] = arr[targetIndex];
    arr[targetIndex] = tmp;
    
}

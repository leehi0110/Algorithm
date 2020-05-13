// 2주차
// array-1

#include <iostream>
#include <vector>
#include <string>

using namespace std;
void reverse_function(vector <int> &arr,int startIndex,int endIndex);

int main()
{
    // ios_base :: sync_with_stdio(false);
    // cin.tie(NULL);
    
    int n, i;
    int repeat;
    
    cin >> n;

    vector <int> arr(n);

    for(i=0;i<n;i++){
        cin >> arr[i];
    }

    cin >> repeat;

    vector <int> reverseArr(repeat*2);

    for(i=0;i<repeat*2;i++){
        cin >> reverseArr[i];
    }

    for(i=0;i<repeat*2;i += 2){
        reverse_function(arr,reverseArr[i],reverseArr[i+1]);
    }

    for(i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    cout << "\n";

}

void reverse_function(vector <int> &arr,int startIndex,int endIndex)
{
    int tmp;

    while(startIndex < endIndex){
        tmp = arr[startIndex];
        arr[startIndex] = arr[endIndex];
        arr[endIndex] = tmp;

        startIndex ++;
        endIndex --;
    }

}
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for(int i=0;i<n;i++){
        int k = arr1[i] | arr2[i];
        string map = "";

        for(int j=n-1;j>=0;j--){
            if(k >= pow(2,j)) {
                map += "#";
                k -= pow(2,j);
            }
            else map += " ";
        }

        answer.push_back(map);
    }

    return answer;
}
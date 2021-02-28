#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> d(n+1,0);

    d[1] = 1;
    d[2] = 2;

    for(int i=3;i<n+1;i++) {
        d[i] = (d[i-2] + d[i-1])%1000000007;
    }

    return d[n];
}
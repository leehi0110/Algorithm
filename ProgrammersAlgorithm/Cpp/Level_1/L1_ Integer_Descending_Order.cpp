#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string str = to_string(n);

    sort(str.begin(), str.end(), greater<char>());
    answer = stoll(str);

    return answer;
}

// long long solution(long long n) {
//     long long answer = 0;

//     vector<int> vec;

//     while(n > 9){
//         vec.push_back(n%10);
//         n /= 10;
//     }
//     vec.push_back(n);
//     sort(vec.begin(),vec.end(),greater<int>());

//     for(int i=0;i<vec.size();i++){
//         answer *= 10;
//         answer += vec[i];
//     }

//     return answer;
// }
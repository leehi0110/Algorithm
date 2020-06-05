#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    for(auto temp : arr)
    {
        answer +=temp;
    }
    answer/=arr.size();
    return answer;
}

// #include <numeric>

// result = accumulate(STL.begin(),STL.end(),init val);
// => long long result일 경우 init val에 0LL으로 해줘야 오류 x

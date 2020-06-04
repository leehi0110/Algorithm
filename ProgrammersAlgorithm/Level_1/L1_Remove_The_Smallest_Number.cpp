#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    
    int min = *min_element(arr.begin(),arr.end());
    int target = find(arr.begin(),arr.end(),min) - arr.begin();
    
    arr.erase(arr.begin() + target);
    
    return arr.empty() ? vector<int>(1,-1) : arr;

}

// #include <algorithm>
// max_element() & min_element()

// 값이 아닌 주소를 반환해줌
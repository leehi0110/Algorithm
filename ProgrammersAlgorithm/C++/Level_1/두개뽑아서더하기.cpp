// ProblemNumber || ProblemName : 두개 뽑아서 더하기
// 문제
// 정수 배열에서 두수를 뽑아 더해 나올 수 있는 모든 경우를 리턴

#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> result;

    for(int i=0;i<numbers.size();i++){
        for(int j=i+1;j<numbers.size();j++){
            int sum = numbers[i] + numbers[j];

            if(result.find(sum) == result.end()) {
                result.insert(sum);
                answer.push_back(sum);
            }
        }
    }

    sort(answer.begin(),answer.end());

    return answer;
}

// 위의 방법 말고
// vector.assign(set.begin(),set.end())를 이용하면 set의 속성으로 자동 정렬된 값을 벡터에 넣을 수 있다.
// => answer.assign(result.begin(),result.end());

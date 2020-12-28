// ProblemNumber || ProblemName : 구명보트
// 문제
// 모든 사람을 구조하기 위해 몇번의 이동이 필요한지 구하시오

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(),people.end());
    
    for(int i=0,j=people.size()-1;;j--) {
        
        if(i >= j) {
            answer = people.size() - i;
            break;
        }
        
        if(people[i] + people[j] <= limit) {
            i++;
        }
    }
    
    return answer;
}

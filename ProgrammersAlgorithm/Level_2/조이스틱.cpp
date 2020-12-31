// ProblemNumber || ProblemName : 조이스틱
// 문제
// 조이스틱을 이용하여 이름을 만드데 필요한 횟수를 구하라

#include <string>
#include <vector>

using namespace std;
int alphCnt(char target);
int leftMove(string name, int now);
int rightMove(string name, int now);

int solution(string name) {
    int answer = 0;
    int now = 0;
    string temp = "";
    string original = name;
    
    for(int i=0;i<name.size();i++) {
        temp += 'A';
    }
    
    while(temp != original) {
        answer += alphCnt(name[now]); // 조이스틱 위아래 움직임에 대한 횟수
        temp[now] = name[now]; // AAAA에서 해당 인덱스 문자 변경
        name[now] = 'A';
        
        int left = leftMove(name,now);
        int right = rightMove(name,now);
        
        if(left < right) {
            answer += left;
            now = (now - left + name.size())%name.size();
        }
        else {
            answer += right;
            now = (now+right + name.size()) %name.size();
        }
    }
    
    return answer;
}

int leftMove(string name, int now) 
{
    int cnt = 0;
    for(int i=0;;i--) {
        if(i == -1) i = name.size()-1;
        
        if(name[i] != 'A') return cnt;
        else cnt++;
    }
}

int rightMove(string name, int now)
{
    int cnt = 0;
    for(int i=now;;i++) {
        if(i == name.size()-1) i = 0;
        
        if(name[i] != 'A') return cnt;
        else cnt ++;
    }
}

int alphCnt(char target)
{
    if(target > 'N') return 'Z' - target + 1;
    else return target - 'A';
}



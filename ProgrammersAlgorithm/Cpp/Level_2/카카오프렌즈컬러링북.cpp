// ProblemNumber || ProblemName : 카카오 프렌즈 컬러링 북
// 문제
// 나눠진 영역의 수와 최대 영역의 수를 구하라

#include <vector>

using namespace std;

int x,y;
int recur(int target,int i,int j,vector<vector<int>> picture);

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    
    vector<int> answer(2,0);
    x = n;
    y = m;
    
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            int area = recur(picture[i][j],i,j,picture);
            if(area != 0) {
                answer[0]++;
                if(answer[1] < area) answer[1] = area;
            }
            else continue;
        }
    }
    
    return answer;
}

int recur(int target,int i,int j,vector<vector<int>> picture) {
    
    if((i>=0 && i < y) && (j >= 0 && j < x)) {
        if(picture[i][j] == target) {
            picture[i][j] = 0;
            return 1 + recur(target,i+1,j,picture) + recur(target,i-1,j,picture) + recur(target,i,j+1,picture) + recur(target,i,j-1,picture);
            
        }
        else return 0;
    }
    else return 0;
}
// 시간 초과 코드
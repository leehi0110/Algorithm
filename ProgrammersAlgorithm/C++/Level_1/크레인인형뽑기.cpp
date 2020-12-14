// ProblemNumber || ProblemName : 크레인 인형뽑기
// 문제
// 크레인 인형뽑기

#include <iostream>
#include <string>

using namespace std;

#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> basket;
    
    for(int i=0;i<moves.size();i++){
        
        int doll = 0;
        
        for(int j=0;j<board.size();j++){
            if(board[j][moves[i]-1] == 0) {
                continue;
            }
            else {
                doll = board[j][moves[i]-1];
                board[j][moves[i]-1] = 0;
                
                if(!basket.empty() && basket.top() == doll) {
                    basket.pop();
                    answer += 2;
                }
                else {
                    basket.push(doll);
                }
                
                break;
            }
        }
    }
    
    return answer;
}
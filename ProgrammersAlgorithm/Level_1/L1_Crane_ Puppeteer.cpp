#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int target;
    deque <int> que;

    for(int i=0;i<moves.size();i++){
        for(int j=0;j<board.size();j++){
            if(board[j][moves[i]-1] == 0) continue;
            else {
                target = board[j][moves[i]-1];
                board[j][moves[i]-1] = 0;

                if(que.size() == 0) que.push_back(target);
                else {
                    if(que.back() == target){
                        que.pop_back();
                        answer += 2;
                    }
                    else que.push_back(target);
                }
                break;
            }
        }
    }
    return answer;
}

#include <string>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map <string, string> chat;

    for(auto s : record){
        stringstream str(s);

        string cmd, uid, name;
        str >> cmd >> uid >> name;

        if(cmd == "Enter"){
            if(chat.find(uid) == chat.end()){
                chat.insert(pair<string, string>(uid,name));
            } 
            else {
                chat[uid] = name;
            }
        }
        else if(cmd == "Change") {
            chat[uid] = name;
        }
    }

    for(auto s : record){
        stringstream str(s);

        string cmd, uid, name;
        str >> cmd >> uid >> name;

        if(cmd == "Enter") {
            answer.push_back(chat[uid] + "님이 들어왔습니다.");
        }
        else if(cmd == "Leave"){
            answer.push_back(chat[uid] + "님이 나갔습니다.");
        }
    }


    return answer;
}
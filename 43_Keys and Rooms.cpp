// 841. Keys and Rooms
// runtime：8 ms Beats 44.39%
// space : 14.15 MB Beats 36.85%

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visted(rooms.size(),false);
        stack<int> s;
        s.push(0); // 從第0間房間開始把鑰匙拿出來解房間
        while(!s.empty()){
            int current=s.top();
            s.pop();
            if(visted[current]==false){ // 如果房間沒被打開過
                visted[current]=true;
                for(int key :rooms[current]){ // 把房間裡的鑰匙取出
                    if(visted[key]==false){ // 如果key對應的房間沒被打開過，才再放到stack裡，因為被開過再有鑰匙也沒意義
                        s.push(key);
                    }
                }
            }
        }
        for(bool room:visted){
            if(room==false){ // 如果有任何一間房間沒被開過，就是錯的
                return false;
            }
        }
        return true;
    }
};
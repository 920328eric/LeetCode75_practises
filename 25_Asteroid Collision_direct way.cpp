// 735. Asteroid Collision
// runtime：16 ms Beats 11.38%
// space : 20.78 MB Beats 35.13%

// direct way in stack

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> pair;
        vector<int> ans;
        for(int i:asteroids){
            if(i>0){
                pair.push(i);
            }
            else{
                if(pair.empty()){
                    ans.push_back(i);
                }
                else{
                    while(!pair.empty()){
                        if(pair.top()<abs(i)){
                            pair.pop();
                        }
                        else if(pair.top()==abs(i)){
                            pair.pop();
                            break;
                        }
                        else{
                            break;
                        }
                        if(pair.empty()){
                            ans.push_back(i);
                        }
                    }
                }
            }
        }
        vector<int> rev;
        while(!pair.empty()){
            rev.push_back(pair.top());
            pair.pop();
        }
        reverse(rev.begin(),rev.end());
        for(int i:rev){
            ans.push_back(i);
        }
        return ans;
    }
};
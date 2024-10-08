// 735. Asteroid Collision
// runtime：7 ms Beats 85.39%
// space : 20.38 MB Beats 82.50%

// optimal way（only use vector to represent stack)

// vector.pop_back();
// vector.back(); the last num in vector

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;
        for(int i:asteroids){
            bool exploded = false;
            while(!stack.empty() && i<0 && stack.back()>0){
                if(stack.back()<-i){
                    stack.pop_back();
                }
                else if(stack.back() == -i){
                    stack.pop_back();
                    exploded=true;
                    break;
                }
                else{
                    exploded=true;
                    break;
                }
            }
            if(!exploded){ // 因為 !exploded 是 true，所以會執行
                stack.push_back(i);
            }
        }
        return stack;
    }
};
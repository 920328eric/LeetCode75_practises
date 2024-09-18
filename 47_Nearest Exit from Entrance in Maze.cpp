// 1926. Nearest Exit from Entrance in Maze
// runtime：92 ms Beats 63.01%
// space : 35.99 MB Beats 55.33%

// pair<int, int> p = {1, 2};
// int x = p.first;
// int y = p.second;
// 固定只有兩個元素

// tuple<int, int, int> t = {1, 2, 3};
// int x = get<0>(t);
// int y = get<1>(t);
// int z = get<2>(t);
// int cy, cx, w; tie(cy, cx, w) = q.front(); // 用來解開 tuple
// tuple 可以有任意數量的元素

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int y = maze.size();
        int yend = maze.size() - 1;
        int x = maze[0].size();
        int xend = maze[0].size() - 1;
        int answer = 0;
        queue<tuple<int,int,int>> q; // (y, x, 步數)
        q.push({entrance[0], entrance[1], 0});
        while(!q.empty()){
            int cy, cx, w;
            tie(cy, cx, w) = q.front();
            q.pop();

            // 如果當前位置已訪問過（標記為 '+'），則跳過。否則，標記為已訪問
            if(maze[cy][cx] == '+') continue;
            maze[cy][cx] = '+';

            // 檢查是否到達出口，如果到達邊界（可能的出口），且不是起始點，則返回步數
            if(cy == 0 || cy == yend || cx == 0 || cx == xend ){
                if(cy == entrance[0] && cx == entrance[1]);
                else return w;
            }

            // 檢查上、下、左、右四個方向，如果是可通行的格子（'.'），就加入 queue
            w++;
            if(cy && maze[cy-1][cx] == '.') q.push({cy-1, cx, w});
            if(cy != yend && maze[cy+1][cx] == '.') q.push({cy+1, cx, w});
            if(cx && maze[cy][cx-1] == '.') q.push({cy, cx-1, w});
            if(cx != xend && maze[cy][cx+1] == '.') q.push({cy, cx+1, w});
        }
        return -1;
    }
};
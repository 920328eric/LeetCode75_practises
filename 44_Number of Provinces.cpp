// 547. Number of Provinces
// runtime：18 ms Beats 80.03%
// space : 18.71 MB Beats 59.87%

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> con(n,false); // 判斷 node 之間有無聯通，已有和別人聯通就為 true
        int ans=0;
        for(int i=0;i<n;i++){
            if(con[i]==false){ // 去發現有沒有沒和別人聯通的 node
                con[i]=true; 
                stack<int> s;
                s.push(i);
                while(!s.empty()){ // 進行 DFS
                    int temp=s.top();
                    s.pop();
                    for(int j=0;j<n;j++){
                        if(isConnected[temp][j]==1&&con[j]==false){ // 去看 node 裡，要和誰聯通，可連成的把他設 true
                            con[j]=true;
                            s.push(j);
                        }
                    }
                }
                ans+=1; // 把這個新的聯通好的 node 讓 ans+1，因為上方的程式碼就是讓這些node聯通成1個
            }
        }
        return ans;
    }
};
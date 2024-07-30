// 2390. Removing Stars From a String
// runtime：75 ms Beats 89.74%
// space : 27.03 MB Beats 71.73%

// stack 用法
// stack<int> sk;
// sk.push(10);
// sk.pop();
// sk.top();
// sk.empty()

class Solution {
public:
    string removeStars(string s) {
        stack<char> re;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                if(!re.empty()){
                    re.pop();
                }
            }
            else{
                re.push(s[i]);
            }
        }
        s="";
        while(!re.empty()){
            s+=re.top();
            re.pop();
        } 
        reverse(s.begin(),s.end());
        return s;
    }
};
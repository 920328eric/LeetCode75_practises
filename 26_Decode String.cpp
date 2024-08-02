// 394. Decode String
// runtime：5 ms Beats 14.02%
// space : 13.04 MB Beats 6.30%

// isalpha(c) 判斷是字母
// isdigit(c) 判斷是數字
// stoi(string) = int 

class Solution {
public:
    string decodeString(string s) {
        stack<char> num;
        for(char n:s){
            if(n!=']'){
                num.push(n);
            }
            else{
                string currentstring="";
                while(!num.empty()&&num.top()!='['){
                    currentstring=num.top()+currentstring; // notice the order of code
                    num.pop();
                }
                num.pop();
                string currentnum="";
                while(!num.empty()&&isdigit(num.top())){ // isdigit is to find int
                    currentnum=num.top()+currentnum;
                    num.pop();
                }
                int count=stoi(currentnum); // chage string to int
                for(int i=0;i<count;i++){
                    for(char ch:currentstring){
                        num.push(ch); // to fix the example of "3[a2[c]]"
                    }
                }

            }
        }
        string res = "";
        while(!num.empty()){
            res=num.top()+res;
            num.pop();
        }
        return res;
    }
};
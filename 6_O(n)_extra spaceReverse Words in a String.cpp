// topic：151. Reverse Words in a String
// runtime：3 ms
// space :10.10 MB 
// O(n) extra space

// vector 會自己擴張容量大小的陣列。所以可以隨便加入或移除元素。
// output.push_back(temp);

class Solution {
public:
    string reverseWords(string s) {
        int sLen = s.size();
        vector<string> output;
        string temp;
        string outoutput;
        for(int i = 0;i<sLen;i++){
            if(s[i] != ' '){
                temp+=s[i];
            }
            else{
                // 遇到字的時候，前面temp為空字串，就變空格加到output裡
                if(!temp.empty()){
                    output.push_back(temp);
                    temp.clear();
                }
            }
        }
        if(!temp.empty()){
            output.push_back(temp);
        }
        reverse(output.begin(),output.end());
        int outputLen = output.size(); 
        for(int i = 0;i<outputLen;i++){
            outoutput += output[i];
            if(i != (outputLen -1)){
                outoutput += ' ';
            }   
        }
        return outoutput;
    }
};
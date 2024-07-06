// topic：151. Reverse Words in a String
// runtime： ms
// space : MB

class Solution {
public:
    string reverseWords(string s) {
        int sLen = s.size();
        vector<string> output(sLen);
        string temp;
        string outoutput;
        int j = 0;
        for(int i = 0;i<sLen;i++){
            if(s[i] != ' '){
                temp+=s[i];
            }
            else{
                output[j] = temp;
                temp = "";
                j++;
            }
        }
        reverse(output.begin(),output.end());
        int outputLen = output.size(); 
        for(int i = 0;i<outputLen;i++){
            outoutput += output[i];
            if(i != (outputLen -1)){
                outoutput += " ";
            }   
        }
        return outoutput;
    }
};
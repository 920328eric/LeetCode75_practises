// 649. Dota2 Senate
// runtime：6 ms Beats 56.76%
// space : 10.66 MB Beats 21.69%

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> ra; // to store the position of Radiant in senate
        queue<int> di; // to store the position of Dire in senate
        int n=senate.size();
        for(int i=0;i<n;i++){
            if(senate[i]=='R'){ // push each position to each queue
                ra.push(i);
            }
            else{
                di.push(i);
            }
        }
        while(!ra.empty()&&!di.empty()){
            int ra_index=ra.front();
            int di_index=di.front();
            ra.pop();
            di.pop();
            if(ra_index<di_index){
                // to ensure Radiant will in the constest next round
                // the position of Radiant which have used it's right already will larger than all of the position of di queue
                // because each senator can exercise right only one time
                ra.push(ra_index+n); 
            }
            else{
                di.push(di_index+n);
            }
        }
        if(ra.empty()){
            return "Dire";
        }
        else{
            return "Radiant";
        }
        
    }
};
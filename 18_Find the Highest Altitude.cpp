// 1732. Find the Highest Altitude
// runtime：0 ms
// space : 10.08 MB 

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int hight = 0,temp = 0;
        for(int i = 0;i<gain.size();i++){
            temp = temp + gain[i];
            hight = max(hight,temp);
        }
        return hight;
    }
};
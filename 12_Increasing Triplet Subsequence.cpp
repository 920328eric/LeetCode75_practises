// 334. Increasing Triplet Subsequence
// runtime：58 ms
// space :61.78 MB 
// O(n) time

class Solution {
public:
    int maxArea(vector<int>& height) {
        int heightLen = height.size();
        int maxarea = 0;
        int left = 0;
        int right = (heightLen-1);
        while(left<right){
            maxarea = max(maxarea,(right-left)*min(height[left],height[right]));
            if(height[right]>height[left]){
                left++;
            }
            else{
                right--;
            }
        }        
        return maxarea;
    }
};
// topic：605. Can Place Flowers
// runtime：3 ms
// space : 22.74 MB

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sizeFlowerbed = flowerbed.size();
        int count = 0;
        if(n==0){
            return true;
        }
        if(sizeFlowerbed == 1 && flowerbed[0] == 0 && n == 1 ){
            return true;
        }
        for(int i = 0;i<sizeFlowerbed;i++){
            if(i == 0){
                if(flowerbed[0] == 0 && flowerbed[1] ==0){
                    count+=1;
                    flowerbed[i] = 1;
                }  
            }
            else if( i == sizeFlowerbed -1){
                if(flowerbed[i] == 0 && flowerbed[i-1] ==0){
                    count+=1;
                    flowerbed[i] = 1;
                }  
            }
            else{
                if(flowerbed[i] == 0 && flowerbed[i-1] ==0 && flowerbed[i+1] ==0){
                    count+=1;
                    flowerbed[i] = 1;
                }  
            }
        }
        if(count >= n){
            return true;
        }
        else{
            return false;
        }
    }
};
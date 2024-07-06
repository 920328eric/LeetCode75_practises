// topic：1431. Kids With the Greatest Number of Candies
// runtime：0 ms
// space : 10.94 MB

// vector<bool>：這是函數的返回類型，表示這個函數將返回一個 bool 型別的向量（vector），即包含多個布林值的容器。
// vector<int>& candies：這是函數的第一個參數，是一個引用（&）型別的整數向量（vector），名為 candies。這個向量存儲了孩子們擁有的糖果數量。
// vector<bool> output(people); //要注意是()

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int people = candies.size();
        vector<bool> output(people);
        int max = candies[0];
        for(int i = 0;i<people;i++){
            if(candies[i]>max){
                max = candies[i];
            }
        }

        for(int i = 0;i<people;i++){
            if((candies[i]+extraCandies) >= max){
                output[i] = true;
            }
            else{
                output[i] = false;
            }
        }

        return output;
    }
};
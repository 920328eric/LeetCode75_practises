// topic：1071. Greatest Common Divisor of Strings
// runtime：0 ms Beats 100.00%
// space : 8.6 MB Beats 65.52%

// key : __gcd(a,b) ，求a、b的最大公因數

// string str = "Hello, World!";
// 提取從索引位置 0 開始的前 5 個字符
// string substr1 = str.substr(0, 5);  // "Hello"
// 提取從索引位置 7 開始到字符串結尾的所有字符
// string substr2 = str.substr(7);     // "World!"

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string str3 = str1 + str2;
        string str4 = str2 + str1;
        int str1Length = str1.length();
        int str2Length = str2.length();
        int outputNum = __gcd(str1Length,str2Length);
        string output;

        if(str3 == str4){
            output = str1.substr(0,outputNum);
        }
        else{
            output = "";
        }

        return output;
    }
};
class Solution {
public:
    int smallestNumber(int n, int t) {
        while(n <= 100){
            int x = n;
            int product = 1;
            while(x > 0){
                product *= x % 10;
                x /= 10;
            }
            if(product % t == 0){
                return n;
            }
            n++;
        }
        return -1;
    }
};
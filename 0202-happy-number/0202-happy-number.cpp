class Solution {
public:
    bool isHappy(int n) {
        int num = n;
        
        while (num != 1) {
            if (num == 4) return false;

            int result = 0;
            while (num) {
                int digit = num % 10;
                result = result + (digit * digit);
                num /= 10;
            }
            num = result;
        }
        
        return true;
    }
};
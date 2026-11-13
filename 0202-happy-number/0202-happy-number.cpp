class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        do {
            slow = next(slow);
            fast = next(next(fast));
        } while (slow != fast);
        
        return slow == 1;
    }

    int next(int x) {
        int result = 0;
        while (x) {
            int digit = x % 10;
            result += (digit * digit);
            x /= 10;
        }
        return result;
    }
};
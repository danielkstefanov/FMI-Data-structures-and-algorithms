class Solution {
public:
    int mySqrt(int x) {
        if (x == 1)
            return 1;
        if (x == 0)
            return 0;

        int right = x;
        int left = 0;

        while (left < right) {
            long mid = left + (right - left) / 2;

            if (mid * mid <= x && (mid + 1) * (mid + 1) > x)
                return mid;

            if (mid * mid >= x)
                right = mid;
            else
                left = mid;
        }

        return -1;
    }
};
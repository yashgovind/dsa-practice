class Solution {
    public:
        double myPow(double x, int n) {
            /*
         we can solve this using binary exponentation
         basically we are trying to reach an even power../
         if we have an even power then we can divide the base by 2 and number by x.
         if it is odd we reduce the base by 1 to make it even

         3^9 = 3*(3^8)--> (3^2)^4--> (9)^4 --> (9^2)^2--> (81)^2--> (81^2)^1--> (6561)^1--> (6561)*(6561)^0 --> 6561. 
            */
            double ans = 1;
            long long num = n;
            if (num < 0) {
                num = -num;
            }
            while (num > 0) {
                if (num % 2 == 1) {
                    ans *= x;
                    num--;
                } else {
                    num /= 2;
                    x *= x;
                }
            }
            if (n < 0) {
                ans = 1.0 / ans;
            }

            return ans;
        }
    };
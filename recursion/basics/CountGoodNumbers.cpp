class Solution {

    /*
 even power -> we can divide the exp by 2 and multiply the number by once to
 optmize it. pow(4,6) --> pow(16,3)--> 16*16*16 which is less operations.
 and less complexity. odd power -> same nothing else
 write power function using binary exponentation and write the countGoodNumber main function.
    */
    const int MOD = 1e9 + 7;

public:
    long long power(long long base, long long exp) {
        long long ans = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                ans = (ans * base) % MOD;
                exp--;
            } else {
                exp = exp / 2;
                base = (base * base) % MOD;
            }
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        // even index -> even number -> (4,odd)
        // odd index-> prime -> (5,even)
        long long even, odd;
        even = (n + 1) / 2;
        odd = n / 2;
        long long oddPlace = power(4, odd);
        long long  evenPlace = power(5, even);
        return (1LL*oddPlace * evenPlace) % (MOD);
    }
};
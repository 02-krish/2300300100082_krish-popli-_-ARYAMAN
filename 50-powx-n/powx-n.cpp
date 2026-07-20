class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;

        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        return Pow(x, N);
    }

    double Pow(double x, long long n) {
        if (n == 0)
            return 1;

        if (n % 2 == 0)
            return Pow(x * x, n / 2);      // even case
        else
            return x * Pow(x, n - 1);      // odd case
    }
};
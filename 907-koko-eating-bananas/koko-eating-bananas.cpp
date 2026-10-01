class Solution {
public:
    long long fun(vector<int>& piles, int n, int speed) {
        long long hr = 0;
        for(int i = 0; i < n; i++) {
            hr += piles[i] / speed;
            if(piles[i] % speed != 0) {
                hr++;
            }
        }
        return hr;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = 0;
        for(int i = 0; i < n; i++) {
            high = max(high, piles[i]);
        }

        int res = high;

        while(low <= high) {
            int guess = low + (high - low) / 2;
            long long hr = fun(piles, n, guess);
            if(hr > h) {
                low = guess + 1;
            }
            else {
                res = guess;
                high = guess - 1;
            }
        }

        return res;
    }
};
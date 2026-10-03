class Solution {
public:
    bool possible(vector<int>& candies ,int n, int guess, long long k){
        long long children = 0;
        for(int i=0; i<n; i++){
            children = children + candies[i]/guess;
        }
        if(children >= k){
            return true;
        }else{
            return false;
        }
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1, high = *max_element(candies.begin(), candies.end());
        int n = candies.size();
        int res = 0;
        while(low<=high){
            int guess = low + (high - low) / 2;
            if(possible(candies,n,guess,k)){
                res = guess;
                low = guess + 1;
            }else{
                high = guess - 1;
            }
        }
        return res;
    }
};
class Solution {
public:
    bool possible(vector<int> &weights, int n, int days, int guess){
        int current_weight = 0;
        int days_taken = 1;
        for(int i=0;i<n;i++){
            if(current_weight + weights[i] <= guess){
                current_weight = current_weight + weights[i];
            }else{
                current_weight = weights[i];
                days_taken++;
            }
        }
        if(days_taken <= days){
            return true;
        }else{
            return false;
        }
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int res = high;
        
        while(low<=high){
            int guess = low+(high-low)/2;
            if(possible(weights,n, days,guess)){
                res =  guess;
                high = guess - 1;
            }else{
                low = guess + 1;
            }
        }
        return res;
    }
};
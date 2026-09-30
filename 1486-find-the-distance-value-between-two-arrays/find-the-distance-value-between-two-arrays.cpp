class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int m = arr1.size();
        // int n = arr2.size();
        sort(arr2.begin(),arr2.end());
        int count = 0;
        for(int x:arr1){
            int low = 0, high = arr2.size()-1;
            while(low <= high){
                int mid = (low+high)/2;
                if(arr2[mid] >= x-d){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }
 if(low == arr2.size() || arr2[low] > x+d){
            count++;
        }
        }
       
        return count;
    }
};
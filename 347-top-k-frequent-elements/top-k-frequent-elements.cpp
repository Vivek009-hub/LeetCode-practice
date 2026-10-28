class Solution {
public:
    struct cmp{
        bool operator()(const pair<int,int>&a, const pair<int,int>&b){
            if(a.first != b.first){
                return a.first > b.first;
            }else{
                return a.second > b.second;
            }
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
       int n = nums.size();
       priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
       unordered_map<int,int>freq;
       for(int i = 0 ;i<n ;i++){
        freq[nums[i]]++;
       }
       for(auto i : freq){
        int element = i.first;
        int frequency = i.second;
        pair<int,int> curr = {frequency , element};

        if(pq.size() < k ){
            pq.push(curr);
            continue;
        }
        if(curr.first < pq.top().first){
            continue;
        }else{
            pq.pop();
            pq.push(curr);
        }
       }
       vector<int> res;
       while(!pq.empty()){
        res.push_back(pq.top().second);
        pq.pop();
       }
       return res;
    }
};
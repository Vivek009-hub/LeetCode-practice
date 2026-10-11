class Solution {
public:
    struct cmp{
        bool operator()(const pair<int,int>&a , const pair<int,int>&b) const{
            if(a.first != b.first){
                return a.first < b.first;
            }else{
                return a.second < b.second;
            }
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>, cmp > pq;

        for(int i=0;i<n;i++){
            int x = points[i][0];
            int y = points[i][1];
            int dist = x*x + y*y;
            pair<int,int> curr = {dist , i};
            
            if(pq.size() < k){
                pq.push(curr);
                continue;
            }
            if(curr.first < pq.top().first){
                pq.pop();
                pq.push(curr);
            }else{
                continue;
            }
        }
        vector<vector<int>> res;
        while(!pq.empty()){
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        return res;
    }
};
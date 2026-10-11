class Solution {
public:
    struct cmp{
        bool operator()(const pair<int,string>&a,const pair<int,string>&b) const{
            if(a.first != b.first){
                return a.first > b.first;
            }else{
                return a.second <  b.second;
            }
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        unordered_map<string,int> f;
        for(string word: words){
            f[word]++;
     
        }

       // Top K , that's why we are using Min Heap
        priority_queue<pair<int,string>,vector<pair<int,string>>, cmp> pq;

        for(auto i :f ){
        string character = i.first;
        int freq = i.second;
        pair<int,string> curr = {freq,character};

        if(pq.size() < k){
            pq.push(curr);
            continue;
        }
        if(curr.first >  pq.top().first || (curr.first == pq.top().first && curr.second < pq.top().second)){
            pq.pop();
            pq.push(curr);
        }else{
            continue;
        }
        }
        vector<string> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        
        return res;
    }
};
class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(m != n){
            return false;
        }
        unordered_map<char,int> st1;
        unordered_map<char,int> st2;

        for(int i = 0 ; i<m; i++){
            st1[s[i]]++;
        }
        for(int i = 0 ; i<n; i++){
            st2[t[i]]++;
        }
        
        return st1 == st2;
        
    }
};
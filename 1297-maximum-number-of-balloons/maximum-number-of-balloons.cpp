class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        unordered_map<char, int> f;

        // Count frequency of every character
        for (char ch : text) {
            f[ch]++;
        }

        // Find how many complete "balloon" words can be formed
        int ans = min({
            f['b'],
            f['a'],
            f['l'] / 2,
            f['o'] / 2,
            f['n']
        });

        return ans;
    }
};
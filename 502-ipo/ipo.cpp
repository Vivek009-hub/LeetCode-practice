
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        vector<pair<int, int>> projects;

        for (int i = 0; i < n; i++) {
            projects.push_back({capital[i], profits[i]});
        }

        sort(projects.begin(), projects.end());

        priority_queue<int> pq;
        int idx = 0;

        while (k--) {
            // Add all currently affordable projects
            while (idx < n && projects[idx].first <= w) {
                pq.push(projects[idx].second);
                idx++;
            }

            // No affordable project exists
            if (pq.empty()) {
                return w;
            }

            // Choose the project with maximum profit
            w += pq.top();
            pq.pop();
        }

        return w;
    }
};

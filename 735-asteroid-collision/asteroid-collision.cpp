class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;

        for (int i = 0 ; i < n ; i++) {

            int asteroid = asteroids[i];

            bool destroyed = false;

            // Collision is possible only when:
            // stack top is moving right (+)
            // current asteroid is moving left (-)
            while (!st.empty() && st.top() > 0 && asteroid < 0) {

                // Stack asteroid is smaller
                if (st.top() < abs(asteroid)) {
                    st.pop();
                }

                // Both asteroids are same size
                else if (st.top() == abs(asteroid)) {
                    st.pop();
                    destroyed = true;
                    break;
                }

                // Stack asteroid is bigger
                else {
                    destroyed = true;
                    break;
                }
            }

            // If current asteroid survived, push it
            if (!destroyed) {
                st.push(asteroid);
            }
        }

        // Convert stack to vector
        vector<int> res;

        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
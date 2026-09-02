class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        int m = tasks.size();

        unordered_map<char, int> freq;
        unordered_map<char, int> free;

        for(int i = 0; i < m; i++) {
            freq[tasks[i]]++;
            free[tasks[i]] = 1;
        }

        priority_queue<pair<int, char>> pq;

        for(auto i : freq) {
            pq.push({i.second, i.first});
        }

        int seat = 1;

        while(!pq.empty()) {

            vector<pair<int, char>> pulled;

            bool done = false;

            while(!pq.empty()) {

                auto P = pq.top();
                pq.pop();

                int fr = P.first;
                char child = P.second;

                if(free[child] <= seat) {

                    // Execute this task
                    if(fr > 1) {
                        pq.push({fr - 1, child});
                    }

                    // This task can be used again after n intervals
                    free[child] = seat + n + 1;

                    done = true;
                    break;
                }
                else {
                    pulled.push_back(P);
                }
            }

            // Put temporarily removed tasks back
            for(auto P : pulled) {
                pq.push(P);
            }

            // If no task could be executed, this is an idle interval
            seat++;
        }

        return seat - 1;
    }
};
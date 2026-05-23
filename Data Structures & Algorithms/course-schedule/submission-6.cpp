class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(numCourses, 0);
        vector<vector<int>> neighbors(numCourses);

        // The problem description is wrong - prerequisites[i] = [a, b] means
        // that you have to take a before taking b.
        for (auto prerequisite : prerequisites) {
            indegrees[prerequisite[1]]++;
            neighbors[prerequisite[0]].push_back(prerequisite[1]);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
            if (indegrees[i] == 0)
                q.push(i);
        
        int finish = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto neighbor : neighbors[cur]) {
                indegrees[neighbor]--;
                if (indegrees[neighbor] == 0)
                    q.push(neighbor);
            }
            finish++;
        }

        return finish == numCourses;
    }
};
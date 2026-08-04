class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(numCourses, 0);
        vector<vector<int>> neighbors(numCourses);
        for (auto prerequisite : prerequisites) {
            neighbors[prerequisite[0]].push_back(prerequisite[1]);
            indegrees[prerequisite[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
            if (indegrees[i] == 0)
                q.push(i);
        int finished = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            finished++;
            for (auto neighbor : neighbors[cur]) {
                indegrees[neighbor]--;
                if (indegrees[neighbor] == 0)
                    q.push(neighbor);
            }
        }
        return finished == numCourses;

        // The problem description is wrong - prerequisites[i] = [a, b] means
        // that you have to take a before taking b.
    }
};
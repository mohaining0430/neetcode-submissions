class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> neighbors(numCourses);
        vector<int> indegrees(numCourses);
        for (const auto prerequisite : prerequisites) {
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
            for (const auto neighbor : neighbors[cur])
                if (--indegrees[neighbor] == 0)
                    q.push(neighbor);
        }

        return finished == numCourses;
    }
};
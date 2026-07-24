class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> adj(numCourses);
        int n = pre.size();
        vector<int> inDeg(numCourses,0);
        for(int i{};i<n;i++){
            adj[pre[i][1]].push_back(pre[i][0]);
            inDeg[pre[i][0]]++;
        }
        queue<int> q;
        for(int i{};i<numCourses;i++){
            if(inDeg[i] == 0) q.push(i);
        }
        int count{};
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for(auto& ele: adj[node]){
                inDeg[ele]--;
                if(inDeg[ele] == 0) q.push(ele);
            }
        }
        return count==numCourses;
    }
};
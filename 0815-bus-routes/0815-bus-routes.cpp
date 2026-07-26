class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n = routes.size();
        if( source == target){
            return 0;
        }
        unordered_map<int,vector<int>>adj;
        for(int route = 0 ; route < n ; route++){
            for(auto &stop : routes[route]){
                adj[stop].push_back(route);
            }
        }
        queue<int>q;
        vector<int>vis(n,0);
        for(auto &it : adj[source]){
            q.push(it);
            vis[it] = 1;
        }
        int busCount = 1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int route = q.front();
                q.pop();
                for(auto &stop : routes[route]){
                    if(stop == target)
                        return busCount;

                    for(auto &nextRoute : adj[stop]){
                        if(!vis[nextRoute]){
                            vis[nextRoute] = 1;
                            q.push(nextRoute);
                        }
                    }
                }
            }
            busCount++;
        }
        return -1;
    }
};
//  https://leetcode.com/problems/second-minimum-time-to-reach-destination/


typedef pair<int,int> pii;
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int t, int c) {
        priority_queue<pii,vector<pii>,greater<pii>>q;
        vector<int>g[n+1];
        for(auto &e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        unordered_map<int,int>cache;
        unordered_set<int>exaust;
        
        q.push({0,1});
        while(!q.empty()){
                auto p=q.top();
                q.pop();
                int curTime=p.first;
                int u=p.second;
                if(u==n && cache.find(u)!= cache.end() && cache[u]<curTime)
                        return curTime;
            if(exaust.find(u)!=exaust.end())continue;
                if(cache.find(u)==cache.end()){
                    cache[u]=curTime;
                }
            else if(cache[u]==curTime)continue;
            else {
                exaust.insert(u);
            }
                
            
                int f=curTime/c;
                if(f & 1)
                    curTime= (f+1)*c;
                
                for(auto &v:g[u]){
                    int visTime=curTime+t;
                    if(exaust.find(v)==exaust.end()){
                    q.push({visTime,v});  
                    }
                }
            
        }
        return -1;
        
    }
};
		
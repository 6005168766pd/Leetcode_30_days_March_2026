class DSU {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void Union(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return;

        if (rank[px] < rank[py]) {
            parent[px] = py;
        }
        else if (rank[px] > rank[py]) {
            parent[py] = px;
        }
        else {
            parent[py] = px;
            rank[px]++;
        }
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};
class Solution {
public:
    bool Check(int n, vector<vector<int>>& edges, int k, int mid){
    DSU dsu(n);
    vector<vector<int>> upgradeCandidates;

    for(auto &edge:edges){
        int u=edge[0];
        int v=edge[1];
        int s=edge[2];
        int m=edge[3];

        if(m==1){
            if(s < mid) return false;
            dsu.Union(u,v);
        }
        else{
            if(s >= mid){
                dsu.Union(u,v);
            }
            else if(2*s >= mid){
                upgradeCandidates.push_back({u,v});
            }
        }
    }

    for(auto &edge:upgradeCandidates){
        int u=edge[0];
        int v=edge[1];

        if(dsu.find(u) != dsu.find(v)){
            if(k <= 0) return false;
            dsu.Union(u,v);
            k--;
        }
    }

    int root = dsu.find(0);

    for(int node=1; node<n; node++){
        if(dsu.find(node) != root)
            return false;
    }

    return true;
}
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        /* INput: n=3, edges = {[0,1,1,1],[1,2,1,1],[2,0,1,1]} , k=0
        0 --1 --2 , parent =0
        (2,0) 2 ka parent 0 hai and 0 ka bi 0 hai so cycle exists and also m=1 which means that edge needs to be included.But that is impossible. */
       DSU dsu(n);
       for(auto &edge:edges){
        int u = edge[0];
        int v = edge[1];
        int s = edge[2];
        int m = edge[3];

        if(m==1){ // must be included in the spanning tree
          if(dsu.find(u) == dsu.find(v)){
            return -1;
          }
          dsu.Union(u,v);
        }
       }
       int result = -1;
       int l = 1;
       int r = 2*1e5;
       while(l<=r){
        int mid = l +(r-l)/2;
        if(Check(n,edges,k,mid)){
            result=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
       }
       return result; 
    }
};

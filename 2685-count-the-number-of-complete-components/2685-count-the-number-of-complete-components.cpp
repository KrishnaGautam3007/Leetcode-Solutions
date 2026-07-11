struct Edge{int v, nxt=-1;};
Edge E[2450];
int eId=0;
int adj[50];// heads for the linked list
void addEdge(int u, int v){
    E[eId]={v, adj[u]};
    adj[u]=eId++;
}

class Solution {
public:
    using int2=pair<int, bool>;
    bitset<50> viz=0;
    int deg[50]={0};
    int2 dfs(int i, int degi){
        viz[i]=1;
        bool alleq=deg[i]==degi;
        int cnt=1;
        for(int idx=adj[i]; idx!=-1; idx=E[idx].nxt){
            int j=E[idx].v;
            if (viz[j]) continue;
            auto [cnt0, alleq0]=dfs(j, degi);
            cnt+=cnt0;
            alleq&=alleq0;
        }
        return {cnt, alleq};
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        const int m=edges.size();
        eId=0;
        memset(adj, -1, n*sizeof(int));
        if(m==n*(n-1)/2) return 1;
        for(int i=0; i<m; i++){
            const int v=edges[i][0], w=edges[i][1];
            addEdge(v, w);
            addEdge(w, v);
            deg[v]++, deg[w]++;
        }
        int ans=0;
        for(int i=0; i<n; i++){
            if (viz[i]) continue;
            const int degi=deg[i];
            auto [cnt, alleq]=dfs(i, degi);
            ans+=(cnt==degi+1 && alleq);
        }
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
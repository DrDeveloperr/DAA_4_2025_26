class Solution {
public:

    int findParent(int x, vector<int>& parent) {
        if (parent[x] == x)
            return x;
        return parent[x] = findParent(parent[x], parent);
    }

    int kruskalsMST(int V, vector<vector<int>>& edges) {

        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });

        vector<int> parent(V);
        for(int i = 0; i < V; i++)
            parent[i] = i;

        int sum = 0;

        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            int pu = findParent(u, parent);
            int pv = findParent(v, parent);

            if(pu != pv) {
                sum += w;
                parent[pv] = pu;
            }
        }

        return sum;
    }
};

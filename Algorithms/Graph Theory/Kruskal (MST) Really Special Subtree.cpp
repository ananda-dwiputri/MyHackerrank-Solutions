struct Edge {
    int s, d, w;
};

struct subset {
    int parent;
    int rank;
};
 
int find(struct subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}
 
void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
 
    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank){
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int edgeComparison(const void* a, const void* b)
{
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->w > b1->w;
}

int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    int E = g_from.size();
    struct Edge* edge = (struct Edge*) malloc(E*sizeof(struct Edge));

    for (int i=0;i<E;++i){
        int s, d, w;
        s = g_from[i];
        d = g_to[i];
        w = g_weight[i];
        edge[i].s = s;
        edge[i].d = d;
        edge[i].w = w;
    }

    qsort(edge, E, sizeof(edge[0]), edgeComparison);

    struct Edge mst[g_nodes-1];
    int mstSize = 0;

    struct subset *subsets = (struct subset*) malloc( g_nodes * sizeof(struct subset) );
    for (int j=0;j<g_nodes;++j) {
        subsets[j].parent = j;
        subsets[j].rank = 0;
    }

    for(int i=0;i<E;i++) {
        struct Edge minEdge = edge[i];
        int x = find(subsets, minEdge.s-1);
        int y = find(subsets, minEdge.d-1);

        if (x != y) {
            mst[mstSize++] = minEdge;
            Union(subsets, x, y);
        }
        if(mstSize == g_nodes-1) {
            break;
        }
    }
    
    int totalWeight = 0;
    for(int i=0;i<g_nodes-1;i++) {
        totalWeight += mst[i].w;
    }
    
    return totalWeight;
}

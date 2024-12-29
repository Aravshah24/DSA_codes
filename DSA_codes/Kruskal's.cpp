#include <iostream>

using namespace std;

struct weight {
    int u, v;
    int w;
};

weight edge[20];
int uf[20];
weight mst[20];

int find(int a[20], int u, int v) {
    if (a[u] == a[v])
        return 1;
    else
        return 0;
}

void Union(int a[20], int n, int u, int v) {
    int temp = a[u];
    for (int i = 0; i < n; i++) {
        if (a[i] == temp) {
            a[i] = a[v];
        }
    }
}

int partition(weight arr[20], int l, int r) {
    int pivot = arr[l].w;
    int i = l;
    int j = r;

    do {
        do {
            i++;
        } while (arr[i].w < pivot && i <= r);

        do {
            j--;
        } while (arr[j].w > pivot);

        if (i < j) {
            swap(arr[i], arr[j]);
        }
    } while (i < j);

    swap(arr[l], arr[j]);
    return j;
}

void quicksort(weight arr[20], int l, int r) {
    if (l < r) {
        int s = partition(arr, l, r);
        quicksort(arr, l, s);
        quicksort(arr, s + 1, r);
    }
}

void kruskal(int n, int e) {
    int arr[20];
    for (int i = 0; i < n; i++)
        arr[i] = i;

    quicksort(edge, 0, e - 1);

    int ecounter = 0;
    int k = 0;

    while (ecounter < n - 1 && k < e) {
        if (find(arr, edge[k].u, edge[k].v) == 0) {
            mst[ecounter++] = edge[k];
            Union(arr, n, edge[k].u, edge[k].v);
        }
        k++;
    }
    if (ecounter!=n-1)
    {
        cout<<"MST cannot be formed"<<endl;
    }
    else
    {
        cout<<"Edges in MST are :"<<endl;
        for(int i=0;i<ecounter;i++)
        {
            cout<<mst[i].u+1<<" "<<mst[i].v+1<<" "<<mst[i].w<<endl;
        }
    }
}

int main() {
    int n, e;

    cout << "Enter the number of vertices:" << endl;
    cin >> n;
    cout << "Enter number of edges:" << endl;
    cin >> e;

    cout << "Enter the edges u v weight:" << endl;
    for (int i = 0; i < e; i++) {
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
        edge[i].u--;
        edge[i].v--;
    }

    kruskal(n, e);

    return 0;
}

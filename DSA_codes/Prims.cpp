#include <iostream>
#include <algorithm>
using namespace std;

class Prim {
public:
    int path[10];
    int dist[10];
    int mstSet[10];

    void initializeMST(int cost[10][10], int source) {
        for (int i = 0; i < 10; i++) {
            path[i] = -1;
            dist[i] = (cost[source][i] == 0) ? 10000000 : cost[source][i];
            mstSet[i] = 0;
        }
        dist[source] = 0;
        mstSet[source] = 1;
    }

    int findMinimum() {
        int mini = 10000000;
        int minIndex = -1;
        for (int i = 0; i < 10; i++) {
            if (!mstSet[i] && dist[i] < mini) {
                mini = dist[i];
                minIndex = i;
            }
        }
        return minIndex;
    }

    void updateMST(int cost[10][10]) {
        int u = findMinimum();
        if (u == -1)
            return;
        mstSet[u] = 1;
        for (int v = 0; v < 10; v++) {
            if (!mstSet[v] && cost[u][v] && cost[u][v] < dist[v]) {
                dist[v] = cost[u][v];
                path[v] = u;
            }
        }
    }

    void primAlgorithm(int cost[10][10], int source) {
        initializeMST(cost, source);
        for (int i = 0; i < 9; i++) // Iterate n-1 times (10-1 = 9)
            updateMST(cost);
    }

    void displayMST(int cost[10][10]) {
        cout << "Edge \tWeight" << endl;
        for (int i = 0; i < 10; i++) {
            if (path[i] != -1 && path[i] != i)
                cout << path[i] << " - " << i << " \t" << cost[path[i]][i] << endl;
        }
    }

    void displayTotalCost(int cost[10][10]) {
        int totalCost = 0;
        for (int i = 0; i < 10; i++) {
            if (path[i] != -1 && path[i] != i) {
                totalCost += cost[path[i]][i];
            }
        }
        cout << "Total cost of the MST is: " << totalCost << endl;
    }
};

int main() {
    int source;
    int cost[10][10];
    cout << "Enter the cost matrix\n";
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
            cin >> cost[i][j];
    }
    cout << "Enter the source vertex: ";
    cin >> source;
    Prim prim;
    prim.primAlgorithm(cost, source);
    prim.displayMST(cost);
    prim.displayTotalCost(cost);
    return 0;
}

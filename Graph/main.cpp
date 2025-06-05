#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool isChain(const unordered_map<int, int>& outDegree, const unordered_map<int, int>& inDegree, int n) {
    int startNodes = 0, endNodes = 0;
    for (int i = 1; i <= n; i++) {
        int inD = inDegree.count(i) ? inDegree.at(i) : 0;
        int outD = outDegree.count(i) ? outDegree.at(i) : 0;

        if (inD == 0 && outD == 1) startNodes++;
        else if (inD == 1 && outD == 0) endNodes++;
        else if (inD == 1 && outD == 1) continue;
        else return false;
    }
    return (startNodes == 1 && endNodes == 1);
}

int main() {
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    unordered_map<int, int> outDegree, inDegree;
    unordered_set<int> nodes;

    cout << "Enter the edges (u v) representing a directed edge from u to v:\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        outDegree[u]++;
        inDegree[v]++;
        nodes.insert(u);
        nodes.insert(v);
    }

    if (nodes.size() != n) {
        cout << "Invalid input: Number of unique nodes does not match n." << endl;
        return 1;
    }

    if (isChain(outDegree, inDegree, n)) {
        cout << "The graph represents a valid chain." << endl;
    } else {
        cout << "The graph is not a valid chain." << endl;
    }

    return 0;
}

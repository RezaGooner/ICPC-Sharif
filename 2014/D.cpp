#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <climits>
#include <set>

using namespace std;

struct Edge {
    int to, weight;
};

int dijkstra(int start, int end, const map<int, vector<Edge>>& graph) {
    map<int, int> dist;
    for (const auto& [node, _] : graph) {
        dist[node] = INT_MAX;
    }
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, current] = pq.top();
        pq.pop();

        if (current == end) return d;

        if (d > dist[current]) continue;

        for (const auto& edge : graph.at(current)) {
            int newDist = d + edge.weight;
            if (newDist < dist[edge.to]) {
                dist[edge.to] = newDist;
                pq.push({newDist, edge.to});
            }
        }
    }

    return -1;
}

int main() {
    while (true) {
        int n, start, end;
        cin >> n >> start >> end;
        if (n == 0 && start == 0 && end == 0) break;

        map<int, vector<Edge>> graph;
        vector<set<int>> elevatorFloors(n);

        for (int i = 0; i < n; i++) {
            int m;
            cin >> m;
            vector<int> floors(m);
            for (int j = 0; j < m; j++) {
                cin >> floors[j];
                elevatorFloors[i].insert(floors[j]);
            }

            for (int x : floors)
                for (int y : floors)
                    if (x != y)
                        graph[x].push_back({y, abs(x - y)});
        }

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                for (int floor : elevatorFloors[i])
                    if (elevatorFloors[j].count(floor))
                        graph[floor].push_back({floor, 0});

        int minTime = dijkstra(start, end, graph);
        cout << minTime << endl;
    }

    return 0;
}

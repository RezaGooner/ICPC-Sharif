#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> c(n + 1);
    vector<int> livesSaved ;
    vector<int> parent(n + 1);
    vector<vector<int>> children(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> c[i];

    for (int i = 2; i <= n; i++) {
        cin >> parent[i];
        children[parent[i]].push_back(i);
    }

    while (q--) {
        int aj, bj;
        cin >> aj >> bj;

        bool visited[n + 1];
        memset(visited, false, sizeof(visited));

        int totalLivesSaved = 0;

        for (int i = aj; i <= bj; i++) {
            if (!visited[i]) {
                totalLivesSaved += c[i];
                visited[i] = true;

                vector<int> stack = {i};
                while (!stack.empty()) {
                    int curr = stack.back();
                    stack.pop_back();
                    for (int child : children[curr]) {
                        if (!visited[child]) {
                            totalLivesSaved += c[child];
                            visited[child] = true;
                            stack.push_back(child);
                        }
                    }
                }
            }
        }

        livesSaved.push_back(totalLivesSaved);
    }

    for (int i : livesSaved)
        cout << i << endl ;

    return 0;
}

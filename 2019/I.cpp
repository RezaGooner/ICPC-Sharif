#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool visited[3][3];

int searchPattern(int i, int j, int nowStepIndex, const string &steps) {
    if (i < 0 || j < 0 || i >= 3 || j >= 3 || visited[i][j]) 
        return 0;
    
    if (nowStepIndex == steps.size()) 
        return 1;

    visited[i][j] = true;
    int count = 0;

    char move = steps[nowStepIndex];

    for (int step = 1; step <= 2; step++) 
        if (move == 'R') 
            count += searchPattern(i, j + step, nowStepIndex + 1, steps);
        else if (move == 'L')
            count += searchPattern(i, j - step, nowStepIndex + 1, steps);
        else if (move == 'U')
            count += searchPattern(i - step, j, nowStepIndex + 1, steps);
        else if (move == 'D')
            count += searchPattern(i + step, j, nowStepIndex + 1, steps);
    

    visited[i][j] = false;
    return count;
}

int main() {
    string pattern;
    cin >> pattern;

    int num = 0;

    for (int i = 0; i < 3; i++) 
        for (int j = 0; j < 3; j++) {
            memset(visited, false, sizeof(visited));
            num += searchPattern(i, j, 0, pattern);
        }
    

    cout << num << endl;

    return 0;
}

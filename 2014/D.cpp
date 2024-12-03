#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

struct HTMLColor {
    string name;
    int r, g, b;
};

double calculateDistance(int r1, int g1, int b1, int r2, int g2, int b2) {
    return sqrt(pow(r1 - r2, 2) + pow(g1 - g2, 2) + pow(b1 - b2, 2));
}

int main() {
    vector<HTMLColor> colors = {
        {"White", 255, 255, 255}, {"Silver", 192, 192, 192}, {"Gray", 128, 128, 128},
        {"Black", 0, 0, 0}, {"Red", 255, 0, 0}, {"Maroon", 128, 0, 0},
        {"Yellow", 255, 255, 0}, {"Olive", 128, 128, 0}, {"Lime", 0, 255, 0},
        {"Green", 0, 128, 0}, {"Aqua", 0, 255, 255}, {"Teal", 0, 128, 128},
        {"Blue", 0, 0, 255}, {"Navy", 0, 0, 128}, {"Fuchsia", 255, 0, 255},
        {"Purple", 128, 0, 128}
    };

    while (true) {
        int r, g, b;
        cin >> r >> g >> b;

        if (r == -1 && g == -1 && b == -1)
            break;

        string closestColor;
        double minDistance = 1e9;

        for (int i = 0; i < colors.size(); i++) {
            double distance = calculateDistance(r, g, b, colors[i].r, colors[i].g, colors[i].b);
            if (distance < minDistance) {
                minDistance = distance;
                closestColor = colors[i].name;
            }
        }

        cout << closestColor << endl;
    }

    return 0;
}

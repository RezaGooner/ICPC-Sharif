#include <iostream>
#include <vector>

struct Position {
    int pos;
    bool isVaccined = false;
};

using namespace std;

int main() {
    int n, l;
    cin >> n >> l;

    vector<Position> p;

    for (int i = 0; i < n; i++) {
        int pos;
        cin >> pos;
        Position tempPosition = {pos};
        p.push_back(tempPosition);
    }

    int notVaccined = p[0].pos ;
    for (int i = 0; i < n - 1; i++) {
        int distance = p[i + 1].pos - p[i].pos;
        if (p[i].pos - notVaccined < l) {
            if (distance < l) {
                if (!p[i].isVaccined && !p[i + 1].isVaccined) {
                    p[i + 1].isVaccined = true;
                    notVaccined = p[i].pos;
                } else if (!p[i].isVaccined) {
                    p[i].isVaccined = true;
                    notVaccined = p[i + 1].pos;
                } else if (!p[i + 1].isVaccined) {
                    if (p[i + 1].pos - notVaccined < l) {
                        p[i + 1].isVaccined = true;
                        notVaccined = p[i - 1].pos;
                    } else 
                        notVaccined = p[i + 1].pos ;
                    
                }
            }
        } else 
            notVaccined = p[i].pos ;
        
    }

    int vaccinatedCount = 0;
    for (const auto& person : p) 
        if (person.isVaccined) 
            vaccinatedCount++;
            

    cout << vaccinatedCount << endl;

    return 0;
}

#include <iostream>

using namespace std;

int main() {
    int infection , hospitalize ;
    cin >> infection ;
    cin >> hospitalize ;

    if (infection <= 50 && hospitalize <= 10)   cout << "White" << endl;
    else if (infection > 30) cout << "Red" << endl ;
    else cout << "Yellow" << endl ;

    return 0;
}

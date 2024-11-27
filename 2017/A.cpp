#include <iostream>
#include <vector>
#include <algorithm>

#define PARSTELLCALL  30
#define PARSTELLDATA  40
#define PARSCELLCALL  35
#define PARSCELLDATA  30
#define PARSPHONECALL 40
#define PARSPHONEDATA 20

using namespace std;

int main() {
    vector<int> result ;
    int call , data , cost ;

    while (true){
        cin >> call >> data ;
        if (call == 0 and data == 0)
            break ;
        int parsTell ,parsCell ,parsPhone ;
        parsTell  = (PARSTELLCALL * call)  + (PARSTELLDATA * data)  ;
        parsCell  = (PARSCELLCALL * call)  + (PARSCELLDATA * data)  ;
        parsPhone = (PARSPHONECALL * call) + (PARSPHONEDATA * data) ;

        result.push_back(min({parsTell, parsCell, parsPhone}));
    }

    for (int i : result){
        cout << i << endl ;
    }
    return 0;
}

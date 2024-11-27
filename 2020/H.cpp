#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int birds , jobs ;
    cin >> birds >> jobs ;
    cin.ignore();
    vector<string> arrange ;

    string line , word;


    getline(cin, line);
    stringstream ss(line);
    while (ss >> word) {
        arrange.push_back(word);
    }


    for (int i = 0 ; i < jobs ; i++){
        getline(cin, line);
        stringstream ss(line);
        vector<string> command;
        while (ss >> word) {
            command.push_back(word);
        }

        if (command[0] == "insert") arrange.insert(arrange.begin() + stoi(command[2]) , command[1]);
        else if (command[0] == "relocate"){
            int tempIndex;
            for (int j = 0; j < arrange.size(); j++) {
                if (arrange[j] == command[1]) {
                    tempIndex = j;
                    break;
                }
            }
            int newIndex = tempIndex + stoi(command[2]);
            arrange.erase(arrange.begin() + tempIndex);
            arrange.insert(arrange.begin() + newIndex, command[1]);

        }
        else if (command[0] == "depart") {
            int tempIndex ;
            for (int j = 0 ; j < arrange.size() ; j++){
                if (arrange[j] == command[1]){
                    tempIndex = j ;
                    break ;
                }
            }
            arrange.erase(arrange.begin() + tempIndex);
        }

    }

    for (int i = 0 ; i < arrange.size() ; i++)
        cout << arrange[i] << " " ;
    cout << endl ;

    return 0;
}

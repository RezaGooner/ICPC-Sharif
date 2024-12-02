#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Vote {
    int id;
    int firstVotes;
    int secondVotes;
    int thirdVotes;
};

int main() {
    vector<string> result;
    string finalResult ;

    while (true) {
        int voter;
        cin >> voter;
        if (voter == 0) {
            break;
        }

        map<int, Vote> votesMap;

        for (int i = 0; i < voter; i++) {
            int voteNum;
            cin >> voteNum;

            for (int j = 0; j < voteNum; j++) {
                int vote;
                cin >> vote;

                if (votesMap.find(vote) == votesMap.end()) {
                    votesMap[vote] = {vote, 0, 0, 0};
                }

                if (j == 0) votesMap[vote].firstVotes++;
                else if (j == 1) votesMap[vote].secondVotes++;
                else if (j == 2) votesMap[vote].thirdVotes++;
            }
        }

        int maxScore = -1;
        vector<int> winners;

        for (const auto& entry : votesMap) {
            int totalScore = entry.second.firstVotes * 3 + entry.second.secondVotes * 2 + entry.second.thirdVotes;
            if (totalScore > maxScore) {
                maxScore = totalScore;
                winners.clear();
                winners.push_back(entry.first);
            } else if (totalScore == maxScore) {
                winners.push_back(entry.first);
            }
        }

        for (int i = 0; i < winners.size(); i++) {
            if (i != 0) finalResult += " ";
            finalResult += to_string(winners[i]);
        }
        finalResult += "\n" ;
    }

    cout << finalResult ;

    return 0;
}

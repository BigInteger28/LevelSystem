#include <iostream>

using namespace std;

float newLevel(int ownLevel, float averageOpponent, float matches, float score) {
    averageOpponent = (int)averageOpponent;
    int maxLevel = 0;
    int maxPromo = (int)(matches / 5);
    float percentage = (score / matches) * 100;
    if (percentage > 69 && ownLevel < averageOpponent) {
        maxPromo += 1;
        if (maxPromo > averageOpponent + 1 - ownLevel) { maxPromo = averageOpponent + 1 - ownLevel; }
        return ownLevel + maxPromo;
    } else if (percentage > 69 && ownLevel == averageOpponent) {
        return ownLevel + 1; 
    } else if (percentage > 59 && ownLevel < averageOpponent) { 
        if (maxPromo > averageOpponent - ownLevel) { maxPromo = averageOpponent - ownLevel; }
        return ownLevel + maxPromo;
    } else if (percentage < 31 && ownLevel == averageOpponent && ownLevel > 1) {
        return ownLevel - 1; 
    } else if (percentage < 41 && ownLevel > averageOpponent && ownLevel > 1) {
        if (maxPromo > ownLevel - averageOpponent) { maxPromo = ownLevel - averageOpponent; }
        return ownLevel - maxPromo;
    }
    return ownLevel;
}

int main() {
    while (1 != 2) {
        int ownLevel;
        float averageOpponent;
        float matches;
        float score;
        float sum;
        string temp;
        
        cout << "\nMatches played: ";
        cin >> matches;
        cout << "Score: ";
        cin >> score;
        cout << "Average level opponents? (y): ";
        cin >> temp;
        if (temp == "y") {
            cout << "Average level opponents: ";
            cin >> averageOpponent;
        } else {
            cout << "Total sum all rating played against: ";
            cin >> sum;
            averageOpponent = sum / matches;
        }
        cout << "Your own level: ";
        cin >> ownLevel;
        cout << "\nAverage opponent is " << averageOpponent << endl;
        cout << "Your new level is " << newLevel(ownLevel, averageOpponent, matches, score) << endl;
    }
}

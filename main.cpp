#include <iostream>

using namespace std;

float newLevel(float ownLevel, float averageOpponent, float matches, float score) {
    int maxLevel = 0;
    int maxPromo = matches / 5;
    if (maxPromo > averageOpponent) {
        maxLevel = (int)averageOpponent;
    } else if (maxPromo < averageOpponent) {
        maxLevel = (int)maxPromo;
    }
    float percentage = (score / matches) * 100;
    if (percentage >= 70 && averageOpponent > ownLevel) {
        return ownLevel + maxLevel;
    } else if (percentage >= 70 && averageOpponent == ownLevel) {
        return ownLevel + 1;
    } else if (percentage <= 30 && averageOpponent < ownLevel && ownLevel > 1) {
        return ownLevel - 1;
    } else if (percentage <= 20 && averageOpponent == ownLevel && ownLevel > 1) {
        return ownLevel - 1;
    }
    return ownLevel;
}

int main() {
    while (1 != 2) {
        float ownLevel;
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

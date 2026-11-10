#include <iostream>
#include <string>
using namespace std;

struct player{
    string name;
    int level;
    int score;
};

void bubble_sort(player players[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - 1 - i; j++){
            if (players[j].level < players[j + 1].level || (players[j].level == players[j + 1].level && players[j].score < players[j + 1].score)){
                player temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }
}

int main(){
    int n;
    player players[10];

    cout << "How many players? ";
    cin >> n;

    if (n < 1 || n > 10){
        cout << "Invalid input! The number of players must be between 1 and 10" << endl;
        return 0;
    }

    cout << "\n=== INPUT PLAYERS ===" << endl;
    for (int i = 0; i < n; i++){
        cout << "\nPlayer " << i + 1 << endl;
        cout << "Name: ";
        cin >> players[i].name;
        cout << "Level (1-10): ";
        cin >> players[i].level;
        cout << "Score: ";
        cin >> players[i].score;
    }

    bubble_sort(players, n);
    cout << "\n============================" << endl;
    cout << "      CoT LEADERBOARD" << endl;
    cout << "============================" << endl;
    for (int i = 0; i < n; i++){
        cout << i + 1 << ". " << players[i].name << " Lv." << players[i].level << " - " << players[i].score << " pts" << endl;
    }
    
    cout << "============================" << endl;
    return 0;
}
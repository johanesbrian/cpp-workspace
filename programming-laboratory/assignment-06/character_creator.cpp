
/*
    ASSIGNMENT 6.2:
    
    Brief:
    You are a Game Developer recently hired by MIPAntasy Studio.
    Your first mission is to create a simple RPG (Role-Playing Game) Character Creator using a C++ struct to store character attributes.
    The program should allow the user to create one character, calculate their total power, and automatically assign a class based on that power.

    Objective:
    Create a simple C++ program that:

    1. Asks the user to create one character by entering:
    - Character name
    - Strength (0-100)
    - Intelligence (0-100)

    2. Calculates the character's total power using the formula:
    Total Power = (Strength * 2) + Intelligence

    3. Automatically assigns a class based on the total power:

    Total Power Range  |  Assigned Class
    >= 150             |  Dragon Knight
    100-149            |  Rogue
    < 100              |  Villager

    4. Displays the complete character information, including all
    attributes, total power, and the assigned class.

    Output Example:
    === Create New Character ===
    Enter name: Ardan
    Enter strength (0-100): 80
    Enter intelligence (0-100): 50

    === Character Info ===
    Name         : Ardan
    Strength     : 80
    Intelligence : 50
    Total Power  : 210
    Class        : Dragon Knight

    Notes:
    1. Use a struct to store all character attributes.
    2. Write all program logic inside the main() function, including
    character input, total power calculation, class determination,
    and information display.
    3. Do not use additional functions or member functions inside the struct.
    4. You do not have to use loops or arrays.
    5. You only need to handle one character for this mission.
*/

#include <iostream>
#include <string>
using namespace std;

struct Character {
    string name;
    int strength;
    int intelligence;
    int totalPower;
    string charClass;
};

int main() {
    Character hero;

    cout << "=== CREATE NEW CHARACTER ===" << endl;
    cout << "Enter name: ";
    getline(cin, hero.name);
    cout << "Enter strength (0-100): ";
    cin >> hero.strength;
    cout << "Enter intelligence (0-100): ";
    cin >> hero.intelligence;

    if (hero.strength < 0 || hero.strength > 100 ||
        hero.intelligence < 0 || hero.intelligence > 100) {
        cout << "\nInvalid input! Strength and intelligence must be 0-100." << endl;
    } else {
        hero.totalPower = (hero.strength * 2) + hero.intelligence;

        if (hero.totalPower >= 150) {
            hero.charClass = "Dragon Knight";
        } else if (hero.totalPower >= 100) {
            hero.charClass = "Rogue";
        } else {
            hero.charClass = "Villager";
        }

        cout << "\n=== CHARACTER INFO ===" << endl;
        cout << "Name         : " << hero.name << endl;
        cout << "Strength     : " << hero.strength << endl;
        cout << "Intelligence : " << hero.intelligence << endl;
        cout << "Total Power  : " << hero.totalPower << endl;
        cout << "Class        : " << hero.charClass << endl;
    }

    return 0;
}

/*
PSEUDOCODE:

DECLARATION
    STRUCT Character
        name         : string
        strength     : integer
        intelligence : integer
        totalPower   : integer
        charClass    : string
    END STRUCT
    hero : Character

ALGORITHM
    OUTPUT "=== CREATE NEW CHARACTER ==="
    OUTPUT "Enter name: "
    INPUT hero.name
    OUTPUT "Enter strength (0-100): "
    INPUT hero.strength
    OUTPUT "Enter intelligence (0-100): "
    INPUT hero.intelligence

    IF hero.strength < 0 OR hero.strength > 100
       OR hero.intelligence < 0 OR hero.intelligence > 100 THEN
        OUTPUT "Invalid input! Strength and intelligence must be 0-100."
    ELSE
        hero.totalPower <- (hero.strength * 2) + hero.intelligence

        IF hero.totalPower >= 150 THEN
            hero.charClass <- "Dragon Knight"
        ELSE IF hero.totalPower >= 100 THEN
            hero.charClass <- "Rogue"
        ELSE
            hero.charClass <- "Villager"
        END IF

        OUTPUT "=== CHARACTER INFO ==="
        OUTPUT "Name         : ", hero.name
        OUTPUT "Strength     : ", hero.strength
        OUTPUT "Intelligence : ", hero.intelligence
        OUTPUT "Total Power  : ", hero.totalPower
        OUTPUT "Class        : ", hero.charClass
    END IF
END
*/
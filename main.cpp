#include <iostream>
using namespace std;

enum MainMenu {
    START = 1,
    EXIT = 2
};

enum AdventureAction {
    REST = 1,
    GO_HUNT = 2,
    EXIT_TO_MAINMENU = 3
};

struct Character {
    string name; // name of character
    int level; // character's level
    int xp; // character's xp
    int hp; // character's health
    int damage; // character's damage
    int gold; // character's gold
};

void showInfoAboutCharacter(Character &info) {
    cout << "Name: " << info.name << " Level: " << info.level << " XP: " << info.xp << " HP: " << info.hp << " Damage: " << info.damage << " Gold: " << info.gold << endl;
}

void playGame(Character &player) {
    bool isPlaying = true;
    int choice;

    while (isPlaying) {
        cout << "---> 1. Rest (Heal +20 HP) <---" << endl;
        cout << "---> 2. Go hunting <---" << endl;
        cout << "---> 3. Exit (Back to main menu) <---" << endl;
        cout << ">> ";
        cin >> choice;

        if (choice == REST) {
            // healing function
            cout << "You are resting" << endl;
        } else if (choice == EXIT_TO_MAINMENU) {
            isPlaying = false;
        }
    }
}


// Character's characteristics
Character player = {"None", 1, 1, 100, 10, 0}; // name, level, xp, hp, damage, gold on start
Character enemy = {"Headcrab", 0, 10, 30, 5, 15}; // name, level, xp, hp, damage, gold


// custom name set function
void setName(Character &player) {
    int choice;

    cout << "Enter name to your character: ";
    cin >> player.name; // set your character's name

    cout << "---> 1. Start Adventure <---" << endl;
    cout << ">> ";
    cin >> choice;
    if (choice == START) {
        playGame(player);
    }
}

// main menu function
void showMainMenu() {
    bool isGameRunning = true;
    int choice;

    while (isGameRunning) {
        cout << "---> Welcome in Last Survivors! <---" << endl;
        cout << "---> 1. Start Game <---" << endl;
        cout << "---> 2. Exit <---" << endl;
        cout << ">> ";
        cin >> choice;

        if (choice == START) {
            setName(player);
        } else if (choice == EXIT) {
            isGameRunning = false;
        }
    }
}


int main() {
    showMainMenu();
    showInfoAboutCharacter(player);
}
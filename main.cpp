#include <iostream>
using namespace std;

enum MainMenu {
    START = 1,
    EXIT = 2
};

enum AdventureAction {
    REST = 1,
    GO_HUNT = 2,
    CHECK_STAT = 3,
    EXIT_TO_MAINMENU = 4
};

struct Character {
    string name; // name of character
    int level; // character's level
    int xp; // character's xp
    int hp; // character's health
    int maxHP; // character's max HP
    int damage; // character's damage
    int gold; // character's gold
};

void showInfoAboutCharacter(Character &info) {
    cout << "Name: " << info.name << " Level: " << info.level << " XP: " << info.xp << " HP: " << info.hp << " Damage: " << info.damage << " Gold: " << info.gold << endl;
}

void restHealing(Character &player) {
    int healCost = 5; // gold cost
    int healAmount = 20; // how much hp you will recieve

    if (player.hp >= player.maxHP) {
        cout << "You do not have to heal" << endl;
    } else if (player.gold < healCost) {
        cout << "You do not have enough money for heal" << endl;
    } else {
        player.hp += healAmount;
        player.gold -= healCost;
        cout << "You were succesfully healed" << endl;
    }
}

void playGame(Character &player) {
    bool isPlaying = true;
    int choice;

    while (isPlaying) {
        cout << "---> 1. Rest (Heal +20 HP) <---" << endl;
        cout << "---> 2. Go hunting <---" << endl;
        cout << "---> 3. Check stats <---" << endl;
        cout << "---> 4. Exit (Back to main menu) <---" << endl;
        cout << ">> ";
        cin >> choice;

        if (choice == REST) { // you are healing your HP
            // healing function
            cout << "You are resting" << endl;
            restHealing(player);

        } else if (choice == CHECK_STAT) { // check your character's stat
            showInfoAboutCharacter(player);

        } else if (choice == EXIT_TO_MAINMENU) { // to exit in main menu
            isPlaying = false;

        }
    }
}


// Character's characteristics
Character player = {"None", 1, 1, 40, 100, 10, 100}; // name, level, xp, hp, damage, gold on start
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
}
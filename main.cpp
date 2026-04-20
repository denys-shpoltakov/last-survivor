#include <iostream>
using namespace std;

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

int main() {
    Character player = {"Player", 1, 1, 100, 10, 0}; // name, level, xp, hp, damage, gold on start
    Character enemy = {"Headcrab", 0, 10, 30, 5, 15}; // name, level, xp, hp, damage, gold

    showInfoAboutCharacter(player);
}
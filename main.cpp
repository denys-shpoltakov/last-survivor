#include <iostream>
#include <ctime>

using namespace std;
class Character {
private:
    string name;
    int hp, damage;

public:
    Character(string n, int h, int d) {
        name = n;
        hp = h;
        damage = d;
    }

    void showInfo() {
        cout << "Name: ";
        cout << "--- " << name << " ---" << endl;
        cout << "HP: ";
        cout << "--- " << hp << " ---" << endl;
        cout << "Damage: ";
        cout << "--- " << damage << " ---" << endl;
    }
};

int main() {
    Character mainHero("John", 100, 10); // name, health, damage
    mainHero.showInfo();
}
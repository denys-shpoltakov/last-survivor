#include <iostream>
#include <ctime>

using namespace std;
class Character {
private:
    string name;
    int hp, damage;

public:
    //================ CONSTRUCTOR ==================
    Character(string n, int h, int d) {
        name = n;
        hp = h;
        damage = d;
    }

    //===================== SHOWING CHARACTER'S CHARACTERISTICS ============================
    void showInfo() {
        cout << "Name: ";
        cout << "--- " << name << " ---" << endl;
        cout << "HP: ";
        cout << "--- " << hp << " ---" << endl;
        cout << "Damage: ";
        cout << "--- " << damage << " ---" << endl;
    }
    //==================== DAMAGE TAKING SYSTEM =============================
    void takeDamage(int dmg) {
        hp -= dmg;
        if (hp < 0) {
            hp = 0;
        }
    }
    
    //==================== ATTACK SYSTEM =============================
    void attack(Character &attacker, Character &victim) {
        // func...
    }
    
    //==================== HEALING SYSTEM =============================
    void heal(int amount) {
        hp += amount;
    }
};

int main() {
    Character mainHero("John", 100, 10); // name, health, damage
    mainHero.showInfo();
    mainHero.takeDamage(25);
    mainHero.showInfo();
}
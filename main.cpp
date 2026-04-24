#include <iostream>
#include <ctime>

using namespace std;
class Character {
private:
    string m_name;
    int m_hp, m_damage;

public:
    //================ CONSTRUCTOR ==================
    Character(string name, int hp, int damage) : m_name(name), m_hp(hp), m_damage(damage) {};

    //===================== SHOWING CHARACTER'S CHARACTERISTICS ============================
    void showInfo() {
        cout << "Name: ";
        cout << "--- " << m_name << " ---" << endl;
        cout << "HP: ";
        cout << "--- " << m_hp << " ---" << endl;
        cout << "Damage: ";
        cout << "--- " << m_damage << " ---" << endl;
    }
    //==================== DAMAGE TAKING SYSTEM =============================
    void takeDamage(int damageAmount) {
        m_hp -= damageAmount;
        if (m_hp < 0) {
            m_hp = 0;
        }
    }
    
    //==================== ATTACK SYSTEM =============================
    void attack(Character &victim) {
        // func...
        cout << m_name << " attacks and dealing: " << m_damage << endl;
        victim.takeDamage(m_damage);
    }
    
    //==================== HEALING SYSTEM =============================
    void heal(int amount) {
        m_hp += amount;
        if (m_hp > 100) {
            m_hp = 100;
        }
    }
};

int main() {
    Character mainHero("John", 100, 110); // name, health, damage
    Character enemy("Zombie", 100, 10); // name, health, damage
    mainHero.showInfo();
    mainHero.attack(enemy);
    mainHero.showInfo();
    enemy.showInfo();

}
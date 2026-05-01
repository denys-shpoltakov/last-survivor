#include <iostream>
using namespace std;

class BaseEntity {
    // по началу тут будет только два атрибута, имя сущности и урон сущности
protected: // это что-то среднее между public или private, классы и его дети видят атрибуты, а main() - нет 
    string m_name; // имя сущности
    int m_damage; // урон сущности
    int m_health; // здоровье сущности
    int m_maxHealth; // максимальное здоровье сущности
    BaseEntity(string name, int damage, int health, int maxHealth) : m_name(name), m_damage(damage), m_health(health), m_maxHealth(maxHealth) {} // Можно создавать только "детей". Это защищает от ошибок, когда ты случайно спавнишь в мире "объект-пустышку"
public:
    virtual void takeDamage(int damage) { // в параметр передаем урон, дальше мы туда передадим урон нашей сущности у которой будет вызываться эта функция
        m_health -= damage;
        if (m_health <= 0) {
            m_health = 0;
            cout << m_name << " got " << damage << " damage!" << " HP: " << m_health << endl;
            // die function
        } else {
            cout << m_name << " got " << damage << " HP: " << m_health << endl;
        }
    }

    virtual void heal(int amount) {
        m_health += amount;
        if (m_health >= m_maxHealth) {
            m_health = m_maxHealth;
            cout << "You have full HP! No need to heal" << endl;
        } else {
            cout << "You have been healed! Your current HP: " << m_health << endl;
        }
    }

    // метод для получения имени сущности
    string getName() const {
        return m_name;
    }

    // метод для получения ХП
    int getHP() const {
        return m_health;
    }

    // метод для атаки
    virtual void attack(BaseEntity* target) = 0;
    // метод разговора
    virtual void talk() = 0; // визуальная функция, которая делает класс абстрактным
    virtual void lvlUp() {} // визуальная функция
    virtual ~BaseEntity() {} // виртуальный диструктор. он необходим для корректного удаления производных объектов через указатель на базовый класс
};

class Player : public BaseEntity {
private:
    int m_xp = 0; // начальное кол-во xp - 0.
    int m_level = 1; // начальный уровень - 1. 

public:
    Player() : BaseEntity("Gordon", 30, 100, 100) {} // собираем игрока с именем: Gordon, с уроном: 20, с единицами здоровья: 100 и с максимальным здоровьем - 100

    void lvlUp() {
        m_level++; // повышаем уровень на 1
        m_damage += 2; // повышаем урон на 2
        m_health += 2; // повышаем здоровье на 2
        m_maxHealth += 2; // повышаем максимальное здоровье на 2
    }

    void attack(BaseEntity* target) override {
        cout << m_name << " attacks a: " << target->getName() << " and dealing: " << m_damage << " damage!" << endl;
        target->takeDamage(m_damage);
    }

    void talk() override {
        cout << "..." << endl; // твоё молчание - убивает.   
    }
};

class Zombie : public BaseEntity {
public:
    Zombie() : BaseEntity("Headcrab", 10, 20, 20) {}

    void attack(BaseEntity* target) override {
        cout << m_name << " attacks a: " << target->getName() << " and dealing: " << m_damage << " damage!" << endl;
        target->takeDamage(m_damage);
    }

    void talk() override {
        cout << "Headcrab sound" << endl;
    }
};


int main() {
    BaseEntity* Gordon = new Player();
    Gordon->talk();
    BaseEntity* Enemy = new Zombie();
    Enemy->talk();
    Gordon->attack(Enemy);
    Gordon->heal(25);
    delete Enemy;
}
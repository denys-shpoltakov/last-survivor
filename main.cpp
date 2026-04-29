#include <iostream>
using namespace std;

class BaseEntity {
    // по началу тут будет только два атрибута, имя сущности и урон сущности
protected: // это что-то среднее между public или private, классы и его дети видят атрибуты, а main() - нет 
    string m_name; // имя сущности
    int m_damage; // урон сущности
    int m_health; // здоровье сущности
    BaseEntity(string name, int damage, int health) : m_name(name), m_damage(damage), m_health(health) {} // Можно создавать только "детей". Это защищает от ошибок, когда ты случайно спавнишь в мире "объект-пустышку"
public:
    virtual void takeDamage(int damage) { // в параметр передаем урон, дальше мы туда передадим урон нашей сущности у которой будет вызываться эта функция
        m_health -= damage;
        if (m_health < 0) {
            m_health = 0;
            cout << m_name << " got " << damage << " damage!" << " HP: " << m_health << endl;
            // die function
        } else {
            cout << m_name << " got " << damage << " HP: " << m_health << endl;
        }
    }

    string getName() {
        return m_name;
    }

    virtual void attack(BaseEntity* target) = 0;
    virtual void talk() = 0; // визуальная функция, которая делает класс абстрактным
    virtual ~BaseEntity() {} // виртуальный диструктор. он необходим для корректного удаления производных объектов через указатель на базовый класс
};

class Player : public BaseEntity {
public:
    Player() : BaseEntity("Gordon", 30, 100) {} // собираем игрока с именем: Gordon, с уроном: 20, с единицами здоровья: 100

    void attack(BaseEntity* target) override {
        cout << m_name << " attacks a: " << target->getName() << " and dealing: " << m_damage << " damage!" << endl;
        target->takeDamage(m_damage);
    }

    void talk() override {
        cout << "Hello World!" << endl;   
    }
};

class Zombie : public BaseEntity {
public:
    Zombie() : BaseEntity("Headcrab", 10, 20) {}

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
}
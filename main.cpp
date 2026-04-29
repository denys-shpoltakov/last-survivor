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
    virtual void talk() = 0; // визуальная функция, которая делает класс абстрактным
    virtual ~BaseEntity() {} // виртуальный диструктор. он необходим для корректного удаления производных объектов через указатель на базовый класс
};

class Player : public BaseEntity {
public:
    Player() : BaseEntity("Gordon", 20, 100) {}

    void talk() override {
        cout << "Hello World!" << endl;   
    }
};

class Zombie : public BaseEntity {
public:
    Zombie() : BaseEntity("Headcrab", 10, 20) {}

    void talk() override {
        cout << "Headcrab sound" << endl;
    }
};


int main() {
    BaseEntity* Gordon = new Player();
    Gordon->talk();
    BaseEntity* Enemy = new Zombie();
    Enemy->talk();
}
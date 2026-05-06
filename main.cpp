#include <iostream>
#include <ctime>
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
        if (m_health >= m_maxHealth) {
            m_health = m_maxHealth;
            cout << "You have full HP! No need to heal" << endl;
        }

        m_health += amount;

        if (m_health > m_maxHealth) {
            m_health = m_maxHealth;
            cout << m_name << " HP has been recovered to maximum. Your current HP: " << m_health << endl;
        } else {
            cout << m_name  << " has been healed by " << amount << ". Current HP: " << m_health << endl;
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
    virtual void die() = 0; // визуальная функция
    virtual void lvlUp() {} // Player её переопределит, а остальные просто проигнорируют.
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
        heal(m_maxHealth); // и регенирируем полностью персонажа при повышении уровня
        cout << "LVL Up! Your damage and health now is: " << endl;
        cout << "Damage: " << m_damage << endl;
        cout << "Health: " << m_health << endl;
    }

    void attack(BaseEntity* target) override {
        cout << m_name << " attacks a: " << target->getName() << " and dealing: " << m_damage << " damage!" << endl;
        target->takeDamage(m_damage);
    }

    void talk() override {
        cout << "..." << endl; // твоё молчание - убивает.   
    }
    
    void die() override {
        cout << "You died!" << endl;
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
    
    void die() override {
        cout << "Enemy died!" << endl;
    }
};

void gamePlay(BaseEntity* player, BaseEntity* enemy) {
    bool isRunning = true;
    int choice;

    cout << "FIGHT IS STARTING!" << endl;

    while (isRunning) {
        if (player->getHP() <= 0) {
            cout << "You died!" << endl; // печатаем текст поражения в консоль
            // заканчиваем игру
            isRunning = false; 
            break;
        }

        if (enemy->getHP() <= 0) {
            cout << "You win!" << endl; // печатаем текст победы в консоль
            player->lvlUp(); // вызываем метод для игрока повышения уровня
            isRunning = false;
            break;
        }

        cout << "Choose your action:" << endl;
        cout << "1. Attack enemy" << endl;
        cout << "2. Heal" << endl;
        cout << "3. Quit" << endl;
        cout << "Enter your choose 1/3: ";
        cin >> choice;

        if (choice == 1) {
            player->attack(enemy);
            enemy->attack(player);
        }

        if (choice == 2) {
            player->heal(25);
        }

        if (choice == 3) {
            cout << "Quiting..." << endl;
            exit(0); // выходим из программы
        }
    }
}

int main() {
    BaseEntity* Gordon = new Player();
    BaseEntity* Enemy = new Zombie();
    gamePlay(Gordon, Enemy);
    delete Gordon;
    delete Enemy;
}
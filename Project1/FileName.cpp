#include <iostream>
#include <string>

// ���� Ŭ���� ���ø�
template <typename T>
class Weapon {
public:
    T damage;
    Weapon(T dmg) : damage(dmg) {
    }

    // ���� ��� �Լ�
    void Use() const {
        std::cout << "Dealing damage: " << damage << std::endl;
    }
};

// ���� ĳ���� Ŭ���� ���ø�
template <typename WeaponType>
class GameCharacter {
public:
    std::string name;
    WeaponType weapon;

    GameCharacter(const std::string charName, const WeaponType charWeapon) : name(charName), weapon(charWeapon) {}

    // ĳ���Ͱ� ���⸦ ����ϴ� �Լ�
    void Attack() const {
        std::cout << name << " attacks with ";
        weapon.Use();
    }
};

int main() {
    // �پ��� ������ ���� ����
    Weapon<int> sword(20);
    Weapon<double> bow(15.5);
    Weapon<std::string> magicWand("Fireball");

    // ������ ���⸦ ����ϴ� ���� ĳ���� ����
    GameCharacter<Weapon<int>> warrior("Warrior", sword);
    GameCharacter<Weapon<double>> archer("Archer", bow);
    GameCharacter<Weapon<std::string>> wizard("Wizard", magicWand);

    // ������ ĳ���Ͱ� ���⸦ ���
    warrior.Attack();
    archer.Attack();
    wizard.Attack();

    return 0;
}
#include <stdexcept>
#include <iostream>

class NoMineral : public std::exception {
public:
    char const* what() const {

        return "Not enough minerals.";
    }
};

class Unit {
public:
    Unit() {};
    Unit(const std::string& race) : race(race) {};
    virtual void createUnit() {};
    std::string getRace();

    /*
    1. virtual function�� createUnit()�� ���弼��.
        - createUnit()�� unit�� create�ϴ� �Լ��Դϴ�.
        - �ϳ��� unit�� ���� ������ 10�� mineral�� �Ҹ��ϰ� �˴ϴ�.
        - unit�� ���������� ������� ��쿡�� unit�� ���������� ��������ٴ� �޼����� �Բ� ���� mineral�� ����մϴ�.
        - ���� ������ mineral�� 10���� ���� ��쿡�� ����ó���� �ؼ� Mineral�� ���ٴ� �޽����� ��켼��.

    2.  mineral variable�� protected�� ���弼��.
        - mineral�� ��� ������ �����ϰ� 100�� ���� ������ ���۵˴ϴ�.
        - mineral variable�� protected�� �������ν� Unit class�� ����� ��� class���� ������ ���� mineral�� ����ϰ� �˴ϴ�.

    3. race variable�� protected�� ���弼��.
        - ��� ������ ������ ���� �̸��� ���� �ֽ��ϴ�.
        - �� Ư���� �ڽ� class���� �����ϰ� ����� �� �ֵ��� protected�� ���弼��.

    4. protected�� ������� �������� ����� ���� getter function�� �ʿ����� Ȯ���ϼ���. (e.g., getMinerals())
    */
protected:
    int mineral = 100;
    std::string race;
    void checkMineral();
    void remainMineral();
};

void Unit::checkMineral() {
    mineral = mineral - 10;
    if (mineral < 0) {
        throw NoMineral();
    };
}

void Unit::remainMineral() {
    std::cout << "A " << race << " unit has been created.Remaining minerals : " << mineral << "\n";
}

std::string Unit::getRace() {
    return race;
}

class ZergUnit : public Unit {
public:
    ZergUnit() : Unit("Zerg") {}
    virtual void createUnit() override;
};

void ZergUnit::createUnit() {
    checkMineral();
    remainMineral();
}

class ProtossUnit : public Unit {
public:
    ProtossUnit() : Unit("Protoss") {};
    virtual void createUnit() override;
};

void ProtossUnit::createUnit() {
    checkMineral();
    remainMineral();
}

class TerranUnit : public Unit {
public:
    TerranUnit() : Unit("Terran") {}
    virtual void createUnit() override;
};

void TerranUnit::createUnit() {
    checkMineral();
    remainMineral();
}

// Function to randomly choose a unit and call its createUnit() function
void randomCreateUnit(Unit& zerg, Unit& terran, Unit& protoss) {
    int randomValue = rand() % 3;  // Generate a random number between 0 and 2

    switch (randomValue) {
    case 0:
        zerg.createUnit();
        break;
    case 1:
        terran.createUnit();
        break;
    case 2:
        protoss.createUnit();
        break;
    }
}

int main() {
    try {
        srand(static_cast<unsigned>(time(0)));  // Seed for random number generation
        Unit unit;
        ZergUnit zergUnit;
        ProtossUnit protossUnit;
        TerranUnit terranUnit;

        unit.createUnit();
        // Trying to create a unit with not enough minerals
        for (int i = 0; i < 50; ++i) {
            randomCreateUnit(zergUnit, terranUnit, protossUnit);
        }

    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
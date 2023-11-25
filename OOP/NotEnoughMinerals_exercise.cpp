#include <iostream>
#include <stdexcept>

class Unit {
public:
    Unit(const std::string& race) : race(race) {}

    /*
    1. virtual function인 createUnit()을 만드세요. 
        - createUnit()은 unit을 create하는 함수입니다. 
        - 하나의 unit을 만들 때마다 10의 mineral을 소모하게 됩니다. 
        - unit이 성공적으로 만들어진 경우에는 unit이 성공적으로 만들어졌다는 메세지와 함께 남은 mineral을 출력합니다. 
        - 만약 보유한 mineral이 10보다 적을 경우에는 예외처리를 해서 Mineral이 없다는 메시지를 띄우세요. 
    
    2.  mineral variable을 protected로 만드세요. 
        - mineral은 모든 종족이 동일하게 100씩 갖고 게임이 시작됩니다. 
        - mineral variable을 protected로 만듦으로써 Unit class를 상속할 모든 class들은 동일한 양의 mineral을 상속하게 됩니다. 
    
    3. race variable을 protected로 만드세요. 
        - 모든 종족은 각자의 종족 이름을 갖고 있습니다. 
        - 이 특성을 자식 class들이 동일하게 상속할 수 있도록 protected로 만드세요. 

    4. protected로 만들어진 변수들을 사용할 때에 getter function이 필요한지 확인하세요. (e.g., getMinerals())
    */
};

class ZergUnit : public Unit {
public:
    /*
    ZergUnit class의 constructor를 작성하세요. 
    (Hint: race) 
    */

   // Write your code here. 
};

class ProtossUnit : public Unit {
public:
    /*
    ProtossUnit class의 constructor를 작성하세요. 
    (Hint: race) 
    */

   // Write your code here. 
};

class TerranUnit : public Unit {
public:
    /*
    TerranUnit class의 constructor를 작성하세요. 
    (Hint: race) 
    */
   
   // Write your code here. 
};


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

        ZergUnit zergUnit;
        ProtossUnit protossUnit;
        TerranUnit terranUnit;

        // Trying to create a unit with not enough minerals
        for (int i = 0; i < 5; ++i) {
        randomCreateUnit(zergUnit, terranUnit, protossUnit);
        }
        
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}


#include <iostream>
using namespace std;

class DayOfYear {
public:
	void input();
	void output();

	void set(int newMonth, int newDay);

	int getMonth();
	int getDay();
private:
	void checkDate();
	int month;
	int day;
};

void DayOfYear::input() {
	cout << "Enter the month as a number : ";
	cin >> month;
	cout << "Enter the day of the month : ";
	cin >> day;
	checkDate();
}

void DayOfYear::output() {
	cout << "month = " << month << ", day = " << day << endl;
}

void DayOfYear::set(int newMonth, int newDay) {
	month = newMonth;
	day = newDay;
	checkDate();
}

void DayOfYear::checkDate() {
	if ((month < 1) || (month > 12) || (day < 1) || (day > 31)) {
		cout << "Illegal date. Aborting program.\n";
		exit(1);
	}
}

int DayOfYear::getMonth() {
	return month;
}

int DayOfYear::getDay() {
	return day;
}

int main() {
	DayOfYear today, bachBirthday;

	cout << "Enter today's date:\n";
	today.input();
	cout << "Today's date is ";
	today.output();

	bachBirthday.set(3, 21);
	cout << "J. S. Bach's birthday is ";
	bachBirthday.output();

	if (today.getMonth() == bachBirthday.getMonth() &&
		today.getDay() == bachBirthday.getDay()) {
		cout << "Happy birthday Johann Sebastian!\n";
	}
	else {
		cout << "Happy unbirthday Johann Sebastian!\n";
	}

	return 0;

}
//DISPLAY 2.15 A do-while Loop
#include <iostream>
using namespace std;
int main()
{
	char ans;
	do {
		cout << "Hello";
		cout << "Do you want another greeting?\n" << "Press y for yes, n for no\n" << "and then press return:";
		cin >> ans;
	} while ((ans == 'y') || (ans == 'Y'));
	cout << "Good-Bye\n";
	// priority�� ���� && ||�� ���� ó���� �޶���
	// Write your code here using do-while loop
	return 0;
}
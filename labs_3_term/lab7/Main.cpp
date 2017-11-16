#include "StudentsHouse.hpp"
#define BUILDINGS_AMOUNT 3
int main() {

	IShowable** showList = new IShowable*[BUILDINGS_AMOUNT];
	showList[0] = new BlockOfFlats(12, "Germanovicha", 100);
	showList[1] = new Dormitory(28, "Yakuba Kolasa", 960, true);
	showList[2] = new StudentsHouse(25, "Trogen, St.Gallen", 1578.5, 20, true, Facade::GlassFacade, "8.00 - wake up");

	for (int i = 0; i < BUILDINGS_AMOUNT; i++)
	{
		showList[i]->Show();
		puts("----------------------------------------");
	}

	delete[] showList;
	system("pause");
	return 0;
}
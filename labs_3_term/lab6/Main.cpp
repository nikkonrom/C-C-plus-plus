#include "StudentsHouse.h"
 
int main() {
	Fachwerk fachwerk(12, "Germanovicha", 1578.5, Facade::GlassFacade);
	Dormitory dormitory(12, "Germanovicha", 20, true);
	StudentsHouse house(12, "Germanovicha", 1578.5, 20, true, Facade::GlassFacade, "8.00 - wake up");
	house.Show();
	return 0;
}
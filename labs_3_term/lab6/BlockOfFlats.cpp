#include "BlockOfFlats.h"



BlockOfFlats::BlockOfFlats()
{
}

BlockOfFlats::BlockOfFlats(int number, std::string street, int numberOfApaprtments) :
	House(number, street), numberOfApaprtments(numberOfApaprtments)
{
}

void BlockOfFlats::Show()
{
	House::Show();
	std::cout << "Nubmer of apartments: " << this->numberOfApaprtments << std::endl;

}


BlockOfFlats::~BlockOfFlats()
{
}

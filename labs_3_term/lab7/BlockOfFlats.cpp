#include "BlockOfFlats.hpp"

#include "StudentsHouse.hpp"

BlockOfFlats::BlockOfFlats()
{
}

BlockOfFlats::BlockOfFlats(int number, std::string street, int numberOfApaprtments) :
	House(number, street), numberOfApaprtments(numberOfApaprtments)
{
	rate = 0.90;
}

void BlockOfFlats::Show()
{
	try
	{
		StudentsHouse& junk = dynamic_cast<StudentsHouse&>(*this);		
	}
	catch (const std::bad_cast& e)
	{
		House::Show();
	}
			
	std::cout << "Nubmer of apartments: " << this->numberOfApaprtments << std::endl;

}

BlockOfFlats::~BlockOfFlats()
{
}

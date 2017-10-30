#include "Class Model\Author.h"
#include "Class Model\Publisher.h"
#include "Class Model\Book.h"
#include "Class Model\Structure.h"
#include "Class Model\Binding.h"
#include <cstdlib>

int main() {
	Author author("Jeffrey Richter", false);
	Publisher publisher("Piter", "OOO ACT");
	Structure structure(HardBinding, 600, 40);
	Cover cover("Main book in .NET developer's library", false);
	Content content(18, false, "IT");
	Book book(structure, author, publisher, content, cover);
	book.Show();
	system("pause");
	return 0;
}
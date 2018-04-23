#include <conio.h>
#include <io_async.h>
int main()
{
	io::io_async io_async;
	io_async.concat_files("input_files", "output.txt");
	_getch();
	return 0;
}

/*
	Zrobiłem z obsługą znaków UTF-8
*/

#include <iostream>
#include <io.h>
#include <fcntl.h>

using std::wcout;
using std::wcerr;
using std::endl;
using std::wstring;
using std::exception;

struct test
{
	wstring text;

	test(wstring text)
	{
		this->text = text;
	}

	~test()
	{
		wcout << "DESTRUCTION! " << text;
	}
};

auto main() -> int
{
	try
	{
		if (_setmode(_fileno(stdout), _O_U8TEXT) == -1)
		{
			throw exception{ "Nie można ustawić kodowania UTF-8" };
		}

		test obiekt{ L"\\(ò_ó)/" };
	}
	catch (exception ex)
	{
		wcerr << "Wyjątek: " << ex.what() << endl;
		return 1;
	}

	return 0;
}
#include <iostream>
#include <string>

using namespace std;

class UI {
public:
	static void ClearScreen()
	{
		cout << "\x1B[2J\x1B[H";
	}
};
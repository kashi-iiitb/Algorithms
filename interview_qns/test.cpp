#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
using std::cout;
using std::setw;
using std::endl;
using std::setfill;
using std::setprecision;
using std::scientific;
using std::fixed;
using std::ostringstream;

int main()
{
	int a = 1000;
	float b = 2.34;
	ostringstream outs;
	cout << setw(10) << setfill('_') << a << endl;
	cout << b << endl;
	 
	cout << scientific << b <<endl;

	outs << sqrt(2.0);
	cout << outs.str() << endl;

	cout << 2-3*5 <<endl;
	return 0;

}

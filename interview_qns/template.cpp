#include <iostream>
using std::cout;
using std::endl;

template <class T>
class greater
{
	bool operator()(const T& x, const T& y) const
	{
		return (x>y);
	}
};

template <class T, class Predicate>
void print(const T& x, const T& y, Predicate& p)
{
	cout << "x,y: " << x << ", "<< y << "Predicate: " << p(x,y) << endl;
}
int main()
{
	print(17,42, greater<int>());
	print(3.14,2.7, greater<double>());

}

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;
class myPredicate{
	public:
		bool operator()(double x) const {return x > 2.0;}

};

int main()
{
	const int kArraySize=10;
	float temp=0;
	vector<float> a(kArraySize);
	for(int i=0; i<kArraySize; i++)
	{
		temp = (i+0.5)/3.14;
		a.push_back(temp);
	}
	partition(a.begin(), a.end(),myPredicate());
	ostream_iterator<float> out(cout, "\n");
	copy(a.begin(),a.end(),out);


}

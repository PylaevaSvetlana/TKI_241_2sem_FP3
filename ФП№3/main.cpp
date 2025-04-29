#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

struct less_abs
{
	bool operator() (int a, int b) const
	{
		return abs(a) < abs(b);
	}
};
int main()
{
	vector<int> V{ 9,8,7,6,5,4,3,2,1 };
	function<bool(int, int)> Func = less_abs();
	sort(V.begin(), V.end(), Func);
	for (int i = 0; i != V.size(); i++)
	{
		cout << V[i];
	}

	return 0;
}
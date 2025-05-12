#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> V1{ 156, 759, 846, 275, 102, 573, 189 };
	vector<int> V2{1489, 104, 718, 12, 865, 179, 48, 267 };
	vector<pair<int, int>> V;

	map<int, vector<int>> M;

	for_each(V2.begin(), V2.end(), [&M](int num) {M[num % 10].push_back(num); });

	for_each(V1.begin(), V1.end(), [&M, &V](int num) 
		{ const auto last_num = num % 10;
		if (!M[last_num].empty())
		{
			V.emplace_back(num, M[last_num].back());
			M[last_num].pop_back();
		}
		});

	cout <<"The size: " << V.size() << endl;
	for_each(V.begin(), V.end(), [](auto p) {cout << p.first << "," << p.second << "   "; });

	return 0;
}
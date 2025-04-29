#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
	vector<int> V1{ 156, 759, 846, 275, 102, 573, 189 };
	vector<int> V2{1489, 104, 718, 12, 865, 179, 48, 267 };
	vector<pair<int, int>> V;

	map<int, vector<int>> M;

	for (auto i = 0; i < V2.size(); i++)
	{
		const int k = V2[i] % 10;
		M[k].push_back(V2[i]);
	}

	for (int i = 0; i < V1.size(); i++)
	{
		const auto last_num = V1[i] % 10;
		if (M[last_num].size() != 0)
		{
			const auto last = M[last_num].size() - 1;
			pair<int, int> temp{ V1[i], M[last_num][last] };
			M[last_num].pop_back();
			V.push_back(temp);
		}
	}

	cout <<"The size: " << V.size() << endl;
	for (auto i = 0; i < V.size(); i++)
	{
		cout << V[i].first << ",";
		cout << V[i].second << "   ";
	}

	return 0;
}
/*
	По данным отрезкам необходимо найти множество точек минимального размера, для которого каждый из отрезков содержит хотя бы одну из точек.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool compareSecond(const std::pair<int, int>& a, const std::pair<int, int>& b) {
	return a.second < b.second;
}

int main()
{
	int n, l, r;
	pair<int, int> p;
	cin >> n;

	vector<pair<int, int>> v;
	for (size_t i = 0; i < n; i++)
	{
		cin >> l >> r;
		p = { l, r };
		v.push_back(p);
	}

	vector<int> pts;
	sort(v.begin(), v.end(), compareSecond);

	int i = 0;
	while (i < v.size()) {
		auto p = v[i++];

		if (pts.empty() || pts[pts.size() - 1] < p.first) {
			pts.push_back(p.second);
		}
	}

	cout << pts.size() << "\n";
	for (auto p : pts) {
		cout << p << " ";
	}

	return 0;
}

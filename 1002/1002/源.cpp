#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
struct Ploynode{
	int zhishu;
	double xishu;
};
int main() {
	vector<Ploynode> p[2];
	Ploynode temp_node;
	int temp = 0;
	for (int i = 0; i < 2; i++) {
		cin >> temp;
		while (temp != 0) {
			cin >> temp_node.zhishu;
			cin >> temp_node.xishu;
			p[i].push_back(temp_node);
			temp--;
		}
	}
	vector<Ploynode> result;
	unsigned int j1 = 0, j2 = 0;
	while (j1 < p[0].size() && j2 < p[1].size()) {
		if (p[0][j1].zhishu == p[1][j2].zhishu) {
			temp_node.zhishu = p[0][j1].zhishu;
			temp_node.xishu = p[0][j1].xishu + p[1][j2].xishu;
			if (temp_node.xishu>1e-6){
				result.push_back(temp_node);
			}
			j1++;
			j2++;
		}
		else if (p[0][j1].zhishu < p[1][j2].zhishu){
			result.push_back(p[1][j2]);
			j2++;
		}
		else {
			result.push_back(p[0][j1]);
			j1++;
		}
	}
	while (j1 != p[0].size()) {
		result.push_back(p[0][j1]);
		j1++;
	}
	while (j2 != p[1].size()) {
		result.push_back(p[1][j2]);
		j2++;
	}
	cout << result.size();
	for (j1 = 0; j1 < result.size(); j1++) {
		cout  << ' ' <<setprecision(0) << result[j1].zhishu
		<< ' ' << setiosflags(ios::fixed | ios::showpoint) << setprecision(1)<< result[j1].xishu;
	}
	cin.get();
	cin.get();
	return 0;
}
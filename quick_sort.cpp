#include <iostream>
#include <vector>

using namespace std;

void quick_sort(vector<int>& vec, int left, int right) {
	if (left < right) {
		int i = left, j = right;
		// int base = v[left];
		while (i < j) {
			while (i < j && vec[j] >= v[left]) {
				j--;
			}
			while (i < j && vec[i] <= v[left]) {
				i++;
			}
			if (i < j) {
				swap(v[i], v[j]);
			}
		}
		swap(v[left], v[i]);

		quick_sort(v, left, i - 1);
		quick_sort(v, i + 1, right);
	}
}

int main() {
	vector<int> v{4, 11, 89, -1, 6};
	quick_sort(v, 0, 4);
	for (auto i : v) {
		cout << i << " ";
	}
	return 0;
}
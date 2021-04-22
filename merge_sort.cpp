#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& vec, int left, int mid, int right) {
	int i = left, j = mid + 1, k = 0;
	int* temp = new int[right - left + 1];

	while (i <= mid && j <= right) {
		if (vec[i] < vec[j]) {
			temp[k] = vec[i];
			i++;
		} else {
			temp[k] = vec[j];
			j++;
		}
		k++;
	}
	while (i <= mid) {
		temp[k] = vec[i];
		k++, i++;
	}
	while (j <= right) {
		temp[k] = vec[j];
		k++, j++;
	}
	for (i = 0; i < right - left + 1; i++) {
		vec[left + i] = temp[i];
	}
	delete[] temp;
}
void merge_sort(vector<int>& vec, int left, int right) {
	if (left >= right) {
		return;
	} 
	int mid = left + (right - left) / 2;
	merge_sort(vec, left, mid);
	merge_sort(vec, mid + 1, right);
	merge(vec, left, mid, right);
}

int main() {
	vector<int> v{4, 11, 89, -1, 6};
	merge_sort(v, 0, 4);
	for (auto i : v) {
		cout << i << " ";
	}
	return 0;
}
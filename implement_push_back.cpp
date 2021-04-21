#include <iostream>
#include <assert.h>
using namespace std;

namespace mystd {

template<typename T>
class MyVector
{
public:
	typedef T* Iterator;
	MyVector(size_t n = 3)
		: start_(new T[n]), end_(start_), max_storage_(start_ + n) { }

	void PushBack(const T& x) {
		check_storage();
		Insert(End(), x);
	} 
	const T& operator[](size_t idx) {
		assert(start_ + idx < end_);
		return start_[idx];
	}
	size_t Capcity() {
		return max_storage_ - start_;
	}
	size_t Size() {
		return end_ - start_;
	}
	void Insert(Iterator pos, const T& x) {
		check_storage();
		Iterator end = End();
		for (Iterator it = end; it != pos; it--) {
			*it = *(it - 1);
		}
		*pos = x;
		end_++;
	}
	Iterator Begin() {
		return start_;
	}
	Iterator End() {
		return end_;
	}
	~MyVector() {
		if (start_) {
			delete[] start_;
		}
	}
	
private:
	Iterator start_;
	Iterator end_;
	Iterator max_storage_;

private:
	void check_storage() {
		if (end_ == max_storage_) {
			size_t sz = Size();
			size_t cap = Capcity();
			T* temp = new T[cap * 2];
			for (size_t i = 0; i < sz; i++) {
				temp[i] = start_[i];

			}
			delete[] start_;
			start_ = temp;
			max_storage_ = start_ + 2 * cap;
			end_ = start_ + sz;
			temp = nullptr;
		}
	}
};
}

int main(int argc, char const *argv[])
{
	mystd::MyVector<int> vec;
	vec.PushBack(1);
	vec.PushBack(2);
	vec.PushBack(3);
	vec.PushBack(4);
	vec.PushBack(5);

	for (int i = 0; i < vec.Size(); i++) {
		cout << vec[i] << endl;
	}

	// cout << vec.Size() << endl;
	cout << vec.Capcity() << endl;


	return 0;
}
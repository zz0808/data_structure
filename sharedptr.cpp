#include <iostream>
#include <mutex>
#include <thread>

template<typename T>
class SharedPtr
{
public:
	SharedPtr(T* ptr=nullptr) 
		: ptr_(ptr), ref_count_(new int(1)), mutex_(new mutex) {
	}
	~SharedPtr() {
		release();
	}
	SharedPtr(const SharedPtr& other) 
		: ptr_(other.ptr_), ref_count_(other.ref_count_), mutex_(other.mutex_){
		add_count();
	}
	SharedPtr& operator=(const SharedPtr& other) {
		if (ptr_ != other.ptr) {
			release();
			ptr_ = other.ptr_;
			ref_count_ = other.ref_count_;
			mutex_ = other.mutex_;
			add_count();
		}
		return *this;
	}

	T& operator*() {
		return *ptr_;
	}

	T* operator->() {
		return ptr_;
	}
	int UseCount() {
		return *ref_count_;
	}


private:
	T* ptr_;
	int* ref_count_;
	mutex* mutex_;

	void add_count() {
		mutex_.lock();
		++(*ref_count_);
		mutex_.unlock();
	}

	void release() {
		bool delete_flag = false;
		mutex_.lock();
		if (--(*ref_count_) == 0) {
			delete ref_count_;
			ref_count_ = nullptr;
			delete ptr_;
			ptr_ = nullptr;
			delete_flag = true;
		}
		mutex_.unlock();
		if (delete_flag) {
			delete mutex_;
			mutex_ = nullptr;
		}
	}
};

int main() {

	SharedPtr<int> sp(new int)

	return 0;
}


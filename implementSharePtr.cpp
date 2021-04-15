#include <iostream>
#include <memory>
#include <thread>

template <typename T>
class SharedPtr
{
public:
	SharedPtr(T* ptr = nullptr) 
		: ptr_(ptr), ref_count_(new int(1)), mutex_(new mutex){
	}

	~SharedPtr() {
		Release();
	}

	SharedPtr(const SharedPtr& rhs) 
		: ptr_(rhs.ptr_), ref_count_(rhs.ref_count_), mutex_(rhs.mutex_) {
		AddCount();
	}

	SharedPtr& operator=(const SharedPtr& rhs) {
		if (ptr_ != rhs.ptr_) {
			ptr_ = rhs.ptr_;
			ref_count_ = rhs.ref_count_;
			mutex_ = rhs.mutex_;
			AddCount();
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
	void AddCount() {
		mutex_.lock();
		++(*ref_count_);
		mutex_.unlock();
	}
	void Release() {
		bool delete_flag = false;
		mutex_.lock();
		if (--(*ref_count_) == 0) {
			delete ptr_;
			delete ref_count_;
			delete_flag = true;
		}
		mutex_.unlock();
		if (delete_flag) {
			delete mutex_;
		}
	}

private:
	T* ptr_;
	int* ref_count_;
	mutex* mutex_;
};

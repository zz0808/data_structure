#include <iostream>
using std::cout;
using std::endl;

class Foo
{
public:
	Foo(int a, int b)
		: a_(a), b_(b) { 
		cout << "init" << endl;
		}

	~Foo(){ }

	// Foo(Foo&& lhs) noexcept {
	// 	cout << "&&" << endl;

	// 	a_ = lhs.a_;
	// 	b_ = lhs.b_;

	// 	lhs.a_ = 0;
	// 	lhs.b_ = 0;
	// }

	Foo(Foo& lhs) {
		a_ = lhs.a_;
		b_ = lhs.b_;

		cout << "&" << endl;
	}

	Foo& operator=(Foo&& lhs) noexcept {
		if (this == &lhs) {
			return *this;
		}
		a_ = lhs.a_;
		b_ = lhs.b_;

		lhs.a_ = 0;
		lhs.b_ = 0;
		cout << "&&=" << endl;

		return *this;
	}
	Foo& operator=(Foo& lhs) noexcept {
		if (this == &lhs) {
			return *this;
		}
		a_ = lhs.a_;
		b_ = lhs.b_;

		lhs.a_ = 0;
		lhs.b_ = 0;
		cout << "&=" << endl;

		return *this;
	}
	int getA() const {
		return a_;
	}

private:
	int a_, b_;
	
};
Foo initFoo(int a, int b) {
	Foo f(a, b);
	return f;
}
int main() {

	Foo f1(1, 2);

	Foo f2(initFoo(3, 4));
	Foo f3(f1);

	// cout << &(initFoo(3, 4));
	cout << f2.getA() << endl;
	cout << f1.getA() << endl;


    return 0;
}
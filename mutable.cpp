#include <iostream>
using namespace std;

struct Node
{	Node(int a, int b)
		: a_(a), b_(b) { }
	mutable int a_, b_;
};

int main() {
	const Node n(3, 5);
	n.a_ = 8;
	cout << n.a_ << endl;
	return 0;
}
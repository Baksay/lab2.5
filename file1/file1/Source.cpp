#include <iostream>
#include <string>
#include "classholder.h"
#include <vector>


using std::endl;
using std::cin;
using std::cout;
using std::cerr;



int main() {

	Vector<int> v2;
	cout << "vec2 is empty? " << (v2.data() == nullptr) << endl;
	v2.push_back(0);
	cout << "vec2 is empty? " << (v2.data() == nullptr) << endl;
	v2.push_back(1);
	v2.push_back(2);
	cout << v2[1] << endl;
	cout << v2.at(1) << endl;
	Vector<int> v(v2);
	cout << "v empty" << v.empty() << endl << endl;
	v.push_back(3);
	cout << "v.capacity = " << v.capacity() << " v.size = " << v.size() << endl;
	v.push_back(4);
	cout << "v.capacity = " << v.capacity() << " v.size = " << v.size() << endl;
	v.push_back(5);
	cout << "v.capacity = " << v.capacity() << " v.size = " << v.size() << endl;
	v.push_back(6);
	cout << "v.capacity = " << v.capacity() << " v.size = " << v.size() << endl;
	v.insert(3, 500);
	v.print();
	cout << "v.capacity = " << v.capacity() << " v.size = " << v.size() << endl;
	v.erase(2);
	v.print();
	cout << "v.capacity = " << v.capacity() << " v.size = " << v.size() << endl;
	v.erase(1, 4);
	v.print();
	cout << "v.capacity = " << v.capacity() << " v.size = " << v.size() << endl << endl;
	cout << "v before";
	v.print();
	cout << "v2 before";
	v2.print();
	v.swap(v2);
	cout << "v after";
	v.print();
	cout << "v2 after";
	v2.print();
	cout << "v back = " << v.back() << endl;
	cout << "v front = " << v.front() << endl;
	cout << "pop back = " << v.pop_back() << endl;
	v.clear();
	cout << "vec is empty? " << v.empty() << endl;


	Vector<const char*> v3;
	v3.push_back("alpha1");
	v3.push_back("alpha2");
	v3.push_back("alpha3");
	Vector<const char*> v4(v3);
	cout << "v empty" << v.empty() << endl << endl;
	v4.push_back("beta1");
	cout << "v.capacity = " << v.capacity() << " v.size = " << v.size() << endl;
	v4.push_back("beta2");
	cout << "v.capacity = " << v.capacity() << " v.size = " << v.size() << endl;
	v4.push_back("beta3");
	cout << "v.capacity = " << v.capacity() << " v.size = " << v.size() << endl;
	v4.push_back("beta4");
	cout << "v.capacity = " << v.capacity() << " v.size = " << v.size() << endl;
	v4.insert(3, "fuf");
	v4.print();
	cout << "c.capacity = " << v.capacity() << " v.size = " << v.size() << endl;
	v4.erase(0);
	v4.print();
	cout << "v.capacity = " << v.capacity() << " v.size = " << v.size() << endl;
	v4.erase(1, 4);
	v4.print();
	cout << "v.capacity = " << v.capacity() << " v.size = " << v.size() << endl << endl;
	cout << "v before";
	v4.print();
	cout << "v2 before";
	v3.print();
	v4.swap(v3);
	cout << "v after";
	v4.print();
	cout << "v2 after";
	v3.print();
	cout << "v back = " << v4.back() << endl;
	cout << "v front = " << v4.front() << endl;
	cout << "pop back = " << v4.pop_back() << endl;
	cout << "v3 is empty???" << v3.empty() << endl;
	v3.clear();
	cout << "v3 is empty???" << v3.empty() << endl;

	Vector<Pair> v5;
	v5.push_back(Pair(2, 1));
	v5.insert(0, Pair(3, 4));
	cout << "v.capacity = " << v.capacity() << " v.size = " << v.size() << endl << endl;
	v5.print();
	v5.push_back(Pair(0, 0));
	v5.push_back(Pair(3, 2));
	v5.print();
	Vector<Pair> v6(v5);
	cout << v6.front() << endl << v6.back() << endl << v6.at(2) << endl;
	v6.insert(2, Pair(40, 20));
	v6.print();
	v6.erase(1, 2);
	cout << "v.capacity = " << v.capacity() << " v.size = " << v.size() << endl << endl;
	cout << "v6 before";
	v6.print();
	cout << "v5 before";
	v5.print();
	v6.swap(v5);
	cout << "v6 after";
	v6.print();
	cout << "v5 after";
	v5.print();
	cout << "v back = " << v6.back() << endl;
	cout << "v front = " << v6.front() << endl;
	cout << "pop back = " << v6.pop_back() << endl;
	v6.clear();
	cout << "v6 is empty? " << v6.empty() << endl;

	cout << endl << std::numeric_limits<size_t>::max() << endl;
	try {
		cout << v.at(7);
	}
	catch (const std::out_of_range& ex) {
		cerr << "Out_of_range: " << ex.what() << endl;
	}

	try {
		cout << v[10] << endl;
	}
	catch (const std::out_of_range& ex) {
		cerr << "Out_of_range: " << ex.what() << endl;
	}

	try {
		Vector<double> vectest;
		vectest.reserve(9999999999999999999);
	}
	catch (const std::bad_alloc& ex) {
		cerr << "Bad_alloc: " << ex.what() << endl;
	}
	try {
		v.insert(100, 0);
	}
	catch (const std::out_of_range& ex) {
		cerr << "Out_of_range: " << ex.what() << endl;
	}

	try {
		v.erase(10, 3);
	}
	catch (const std::out_of_range& ex) {
		cerr << "Out_of_range: " << ex.what() << endl;
	}

	return 0;
}
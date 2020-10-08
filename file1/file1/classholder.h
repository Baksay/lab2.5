#pragma once
#include <iostream>
#include "Vector.cpp"

class Pair {
private:
	int left;
	int right;
public:
	inline Pair() {};
	inline Pair(int val1, int val2) : left(val1), right(val2) {};
	friend std::ostream& operator<<(std::ostream& out, const Pair& p) {
		out << p.left << "\t" << p.right;
		return out;
	}
};

template <class T>
class Vector {
private:
	T* dat;
	size_t siz;
	size_t nofcontent;
public:
	Vector();
	Vector(const Vector& vec);
	~Vector();

	Vector& operator=(const Vector& vec);
	T& operator[](const size_t& index);
	T at(const size_t& pos) const;
	T front();
	T back();
	bool empty();
	size_t size() const;
	void reserve(const size_t& n);
	size_t capacity() const;
	void clear();
	void insert(const size_t& pos, T val);
	void erase(const size_t& pos);
	void erase(const size_t& r1, const size_t& r2);
	void push_back(T val);
	T pop_back();
	void resize(const size_t& count);
	void print() const;
	void swap(Vector<T>& oth);

	T* data();
};


template class Vector<int>;
template class Vector<const char*>;
template class Vector<Pair>;

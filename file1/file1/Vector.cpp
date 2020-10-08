#include "classholder.h"
#include <iostream>


using std::endl;
using std::cout;
using std::cin;

template<class T>
Vector<T>::Vector(const Vector& v) {			
	siz = v.siz;
	nofcontent = v.nofcontent;
	dat = new T[siz];
	for (size_t i = 0; i < siz; ++i) {
		dat[i] = v.dat[i];
	}
}

template<class T>
Vector<T>::Vector() {
	siz = 0;
	nofcontent = 0;
	dat = nullptr;
}

template<class T>
Vector<T>::~Vector() {
	delete[] dat;
	dat = nullptr;
}

template <class T>
T& Vector<T>::operator[](const size_t& index) {
	if (index > siz) {
		throw std::out_of_range("wrong index");
	}
	return dat[index];
}

template <class T>
T Vector<T>::at(const size_t& pos) const {
	if (pos >= siz) {
		throw std::out_of_range("wrong index");
	}
	return dat[pos];
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& vec) {
	delete[] dat;
	siz = vec.siz;
	nofcontent = vec.nofcontent;
	dat = new T[siz];

	for (size_t i = 0; i < vec.siz; ++i) {
		dat[i] = vec.dat[i];
	}
	return *this;
}

template <class T>
T Vector<T>::front() {
	return dat[0];
}

template <class T>
T Vector<T>::back() {
	return dat[siz - 1];
}

template <class T>
bool Vector<T>::empty() {
	return siz ? false : true;
}

template<class T>
size_t Vector<T>::size() const {
	return siz;
}

template<class T>
void Vector<T>::reserve(const size_t& n) {
	if (n > std::numeric_limits<size_t>::max()) {
		throw std::length_error("length error");
	}
	if (n > nofcontent) {
		nofcontent = n;
		T* newData = new T[n];
		for (size_t i = 0; i < siz; ++i) {
			newData[i] = dat[i];
		}
		delete[] dat;
		dat = newData;
	}
}

template<class T>
size_t Vector<T>::capacity() const {
	return nofcontent;
}

template<class T>
void Vector<T>::clear() {
	siz = 0;
	nofcontent = 0;
	delete[] dat;
	dat = nullptr;
}

template<class T>
void Vector<T>::insert(const size_t& pos, T val) {
	if (pos >= siz) {
		throw std::out_of_range("wrong index");
	}
	size_t newSize;
	if (nofcontent > siz) {
		++siz;
		T tmp2;
		T tmp1 = val;

		for (size_t i = pos; i < siz; ++i) {
			tmp2 = dat[i];
			dat[i] = tmp1;
			tmp1 = tmp2;

		}

	}
	else {
		size_t newcapa;
		switch (nofcontent) {
		case 0: newcapa = 1; break;
		case 1: newcapa = 2; break;
		default: newcapa = nofcontent * 1.5;
		}
		T* newData = new T[newcapa];
		for (size_t i = 0; i < pos; ++i) {
			newData[i] = dat[i];
		}
		newData[pos] = val;
		for (size_t i = pos; i < siz; ++i) {
			newData[i + 1] = dat[i];
		}
		nofcontent = newcapa;
		++siz;
		delete[] dat;
		dat = newData;
	}
}

template<class T>
void Vector<T>::erase(const size_t& pos) {
	if (pos >= siz) {
		throw std::out_of_range("wrong index");
	}
	--siz;
	for (size_t i = pos; i < siz; ++i) {
		dat[i] = dat[i + 1];
	}
}


template<class T>
void Vector<T>::erase(const size_t& r1, const size_t& r2) {
	if (r1 > r2 || r2 >= siz) {
		throw std::out_of_range("wrong index");
	}
	for (size_t i = 0; i < siz - r2; ++i) {
		dat[i + r1] = dat[i + r2];
	}
	siz -= r2 - r1;
}


template<class T>
void Vector<T>::push_back(T val) {
	size_t newCapacity;
	if (siz > 1 && nofcontent >= siz + 1) {
		dat[siz] = val;
		++siz;
	}
	else {
		if (siz > 1) {
			newCapacity = static_cast<size_t>(nofcontent * 1.5);
		}
		else {
			newCapacity = siz + 1;
		}
		T* newData = new T[newCapacity];
		for (size_t i = 0; i < siz; ++i) {
			newData[i] = dat[i];
		}
		newData[siz] = val;
		delete[] dat;
		dat = newData;
		siz = siz + 1;
		nofcontent = newCapacity;
	}
}

template<class T>
T Vector<T>::pop_back() {
	--siz;
	return dat[siz];
}

template <class T>
void Vector<T>::swap(Vector<T>& oth) {
	Vector<T> tmpVec;
	tmpVec = oth;
	oth = *this;
	*this = tmpVec;
}

template<class T>
void Vector<T>::resize(const size_t& count) {
	size_t minSize = count;
	if (count > siz) {
		nofcontent = count;
		minSize = siz;
	}
	T* newData = new T[count];
	for (size_t i = 0; i < minSize; ++i) {
		newData[i] = dat[i];
	}
	delete[] dat;
	dat = newData;
	siz = minSize;
	nofcontent = count;
}

template <class T>
void Vector<T>::print() const {
	for (size_t i = 0; i < siz; ++i) {
		cout << "element[" << i << "] = " << dat[i] << endl;
	}
}

template <class T>
T* Vector<T>::data() {
	return siz == 0 ? nullptr : dat;
}
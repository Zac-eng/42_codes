#include "Array.hpp"

template <typename T>
Array<T>::Array(void) {
	this->_elements = new T[0];
	this->_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n) {
	this->_elements = new T[n];
	this->_size = static_cast<std::size_t>(n);
}

template <typename T>
Array<T>::Array(const Array& object) {
	*this = object;
}

template <typename T>
Array<T>::~Array() {
	delete[] this->_elements;
}

template <typename T>
Array<T>& Array<T>::operator = (const Array<T>& object) {
	this->_size = object.size();
	this->_elements = new T[this->_size];
	for (std::size_t i = 0; i < this->_size; i++) {
		this->_elements[i] = object[i];
	}
	return *this;
}

template <typename T>
T& Array<T>::operator [] (int index) {
	if (index < 0 || static_cast<std::size_t>(index) >= this->_size) {
		throw std::exception();
	}
	return this->_elements[index];
}

template <typename T>
T Array<T>::operator [] (int index) const {
	if (index < 0 || static_cast<std::size_t>(index) >= this->_size) {
		throw std::exception();
	}
	return this->_elements[index];
}

template <typename T>
std::size_t Array<T>::size(void) const {
	return this->_size;
}

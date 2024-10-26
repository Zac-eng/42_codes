#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(void) {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& object) {
	*this = object;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator = (const MutantStack<T>& object) {
	*this = object;
}

template <typename T>
class MutantStack<T>::iterator {

private:
	std::stack<T> *_stack_ptr;
	std::size_t _index;
	iterator(void);

public:
	iterator(std::stack<T>* init_ptr, std::size_t init_index): _stack_ptr(init_ptr), _index(init_index) {}
	iterator(const iterator& object) {
		*this = object;
	}
	iterator& operator = (const iterator& object) {
		this->_stack_ptr = object._stack_ptr;
		this->_index = object._index;
		return *this;
	}
	~iterator() {}
	const T& operator * () const {
		std::stack<T> temp_stack;
		T top_value;

		for (std::size_t i = 0; i < this->_index; i++) {
		std::cout << _stack_ptr->top() << std::endl;
			top_value = _stack_ptr->top();
			_stack_ptr->pop();
			temp_stack.push(top_value);
		}
		const T& ret_val = _stack_ptr->top();
		for (std::size_t i = 0; i < this->_index; i++) {
			std::cout << temp_stack.top() << std::endl;
			top_value = temp_stack.top();
			temp_stack.pop();
			_stack_ptr->push(top_value);
		}
		return ret_val;
	}
	T& operator * () {
		std::stack<T> temp_stack;
		T top_value;

		for (std::size_t i = 0; i < this->_index; i++) {
			top_value = _stack_ptr->top();
		std::cout << _stack_ptr->top() << std::endl;
			_stack_ptr->pop();
			temp_stack.push(top_value);
		}
		T& ret_val = _stack_ptr->top();
		for (std::size_t i = 0; i < this->_index; i++) {
			top_value = temp_stack.top();
			temp_stack.pop();
			_stack_ptr->push(top_value);
		}
		return ret_val;
	}
	bool operator == (const iterator& object) {
		return *(*this) == *object;
	}
	bool operator != (const iterator& object) {
		return *(*this) != *object;
	}
	iterator& operator ++ () {
		this->_index += 1;
		return *this;
	}
	iterator operator ++ (int) {
		this->_index += 1;
		return *this;
	}
	iterator& operator -- () {
		this->_index -= 1;
		return *this;
	}
	iterator operator -- (int) {
		this->_index -= 1;
		return *this;
	}

};

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return iterator(this, 0);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return iterator(this, this->size());
}

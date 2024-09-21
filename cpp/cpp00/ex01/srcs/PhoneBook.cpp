#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	for (int i = 0; i < 8; i++) {
		this->contacts_[i] = NULL;
	}
	this->next_index_ = 0;
	this->contact_count_ = 0;
}

PhoneBook::~PhoneBook(void) {
	for (int i = 0; i < this->contact_count_; i++) {
		delete this->contacts_[i];
	}
}

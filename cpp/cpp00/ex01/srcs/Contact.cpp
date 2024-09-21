#include "Contact.hpp"

Contact::Contact(std::string fname, std::string lname, std::string nname, std::string phone_number, std::string secret) {
	this->_firstName = fname;
	this->_lastName = lname;
	this->_nickname = nname;
	this->_phoneNumber = phone_number;
	this->_darkestSecret = secret;
}

Contact::~Contact() {}

#include "PhoneBook.hpp"
#include "Contact.hpp"

bool  PhoneBook::addContact(void) {
	std::string contact_info[5];

	std::cout << "Please input the contact information, first name, last name, nickname, phone number, and darkest sectret" << std::endl;
    std::cout << "First name: " << std::endl;
    std::cin >> contact_info[0];
    if (contact_info[0].empty())
    	return false;
    std::cout << "Last name: " << std::endl;
    std::cin >> contact_info[1];
    if (contact_info[1].empty())
    	return false;
    std::cout << "Nickname: " << std::endl;
    std::cin >> contact_info[2];
    if (contact_info[2].empty())
        return false;
    std::cout << "Phone number: " << std::endl;
    std::cin >> contact_info[3];
    if (contact_info[3].empty())
        return false;
    std::cout << "Darkest secret: " << std::endl;
    std::cin >> contact_info[4];
    if (contact_info[4].empty())
    	return false;
	Contact	*newConact = new Contact(contact_info[0], contact_info[1], contact_info[2], contact_info[3], contact_info[4]);
	if (this->contact_count_ == 8) {
		delete this->contacts_[next_index_];
	}
	this->contacts_[next_index_] = newConact;
	this->next_index_ = (this->next_index_ + 1) % 8;
	if (this->contact_count_ < 8) {
		this->contact_count_ += 1;
	}
	return true;
}

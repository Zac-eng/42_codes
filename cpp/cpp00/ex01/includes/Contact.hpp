#ifndef CONTACT_H
# define CONTACT_H

# include <string>
# include <iostream>

class Contact {
  public:
    Contact(std::string fname, std::string lname, std::string nname, \
            std::string phone_number, std::string secret);
    ~Contact(void);
    void	showContact(void);
    void  showAbstruct(int index);

  private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;
};

#endif

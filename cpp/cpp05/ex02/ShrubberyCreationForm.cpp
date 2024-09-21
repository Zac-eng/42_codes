#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): _sign_grade(SHRUBBERY_SIGN_GRADE), _exec_grade(SHRUBBERY_EXEC_GRADE) {
	this->setName("default");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): _sign_grade(SHRUBBERY_SIGN_GRADE), _exec_grade(SHRUBBERY_EXEC_GRADE) {
	this->setName(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& object) {
	*this = object;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm& object) {
	this->setName(object.getName());
	return *this;
}

bool ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	ofstream	file;

	if (this->_signed == false || executor.getGrade() < this->_exec_grade)
		return false;
	file.open(this->_name + "_shrubbery");
	if (!file)
	{
		std::cout << "failed to create " << this->getName() + "_shrubbery" << std::endl;
		return false;
	}
	file << "                                                         .\
                                              .         ;  \
                 .              .              ;%     ;;   \
                   ,           ,                :;%  %;   \
                    :         ;                   :;%;'     .,   \
           ,.        %;     %;            ;        %;'    ,; \
             ;       ;%;  %%;        ,     %;    ;%;    ,%'\
              %;       %;%;      ,  ;       %;  ;%;   ,%;' \
               ;%;      %;        ;%;        % ;%;  ,%;'\
                `%;.     ;%;     %;'         `;%%;.%;'\
                 `:;%.    ;%%. %@;        %; ;@%;%'\
                    `:%;.  :;bd%;          %;@%;'\
                      `@%:.  :;%.         ;@@%;'   \
                        `@%.  `;@%.      ;@@%;         \
                          `@%%. `@%%    ;@@%;        \
                            ;@%. :@%%  %@@%;       \
                              %@bd%%%bd%%:;     \
                                #@%%%%%:;;\
                                %@@%%%::;\
                                %@@@%(o);  . '         \
                                %@@@o%;:(.,'         \
                            `.. %@@@o%::;         \
                               `)@@@o%::;         \
                                %@@(o)::;        \
                               .%@@@@%::;         \
                               ;%@@@@%::;.          \
                              ;%@@@@%%:;;;. \
                          ...;%@@@@@%%:;;;;,.." << std::endl;
	file.close();
	return true;

}

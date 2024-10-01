#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("default", SHRUBBERY_SIGN_GRADE, SHRUBBERY_EXEC_GRADE) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm(target, SHRUBBERY_SIGN_GRADE, SHRUBBERY_EXEC_GRADE) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& object): AForm(object) {
	*this = object;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm& object) {
  (void)object;
  return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	std::ofstream	file;

	checkExecutable(executor);
	file.open((this->getName() + "_shrubbery").c_str());
	if (!file)
	{
		std::cout << "failed to create " << this->getName() + "_shrubbery" << std::endl;
		return ;
	}
	file << "                                                         .\n"
<< "                                              .         ;  \n"
"                 .              .              ;%     ;;   \n"
"                   ,           ,                :;%  %;   \n"
"                    :         ;                   :;%;'     .,   \n"
"           ,.        %;     %;            ;        %;'    ,; \n"
"             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
"              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n"
"               ;%;      %;        ;%;        % ;%;  ,%;'\n"
"                `%;.     ;%;     %;'         `;%%;.%;'\n"
"                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
"                    `:%;.  :;bd%;          %;@%;'\n"
"                      `@%:.  :;%.         ;@@%;'   \n"
"                        `@%.  `;@%.      ;@@%;         \n"
"                          `@%%. `@%%    ;@@%;        \n"
"                            ;@%. :@%%  %@@%;       \n"
"                              %@bd%%%bd%%:;     \n"
"                                #@%%%%%:;;\n"
"                                %@@%%%::;\n"
"                                %@@@%(o);  . '         \n"
"                                %@@@o%;:(.,'         \n"
"                            `.. %@@@o%::;         \n"
"                               `)@@@o%::;         \n"
"                                %@@(o)::;        \n"
"                               .%@@@@%::;         \n"
"                               ;%@@@@%::;.          \n"
"                              ;%@@@@%%:;;;. \n"
"                          ...;%@@@@@%%:;;;;,.." << std::endl;
	file.close();

}

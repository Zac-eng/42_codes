#ifndef DATA_HPP
# define DATA_HPP

# include <string>

class Data {

private:
  std::string _content;

public:
  Data(void);
  Data(std::string input);
  Data& operator = (const Data& object);
  ~Data();
  std::string readContent() const;
  void overwriteContent(std::string);
  void appendContent(std::string);

};

#endif

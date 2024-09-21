#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

# define IDEA_CAP 100

class Brain {

private:
    std::string ideas[IDEA_CAP];

public:
    Brain(void);
    Brain(Brain& object);
    ~Brain();
    Brain& operator = (const Brain& object);

};

#endif

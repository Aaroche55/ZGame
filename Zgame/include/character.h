#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
public:
    // Constructor
    Character(const std::string& name);

    // Destructor
    ~Character();

    // Member functions
    void setName(const std::string& name);
    std::string getName() const;


private:
    std::string m_name;
    int m_health;
};

#endif // CHARACTER_H

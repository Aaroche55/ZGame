#ifndef PLAYER_H
#define PLAYER_H

#include <string>

namespace Game {
    class Player {
    public:
        Player(const std::string& name); // Constructor declaration
        // Additional member functions and variables

    private:
        std::string name;

    };
}

#endif // PLAYER_H

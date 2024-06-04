#ifndef GAMEEXCEPTION_H
#define GAMEEXCEPTION_H

#include <stdexcept>

namespace Game {

    class GameException : public std::runtime_error {
    public:
        GameException(const std::string& message) : std::runtime_error(message) {}
    };

} // namespace Game

#endif // GAMEEXCEPTION_H

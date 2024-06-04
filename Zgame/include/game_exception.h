#ifndef GAME_EXCEPTION_H
#define GAME_EXCEPTION_H

#include <stdexcept>
#include <string>

namespace Game {

    class GameException : public std::runtime_error {
    public:
        explicit GameException(const std::string& message)
                : std::runtime_error(message) {}
    };

} // namespace Game

#endif // GAME_EXCEPTION_H

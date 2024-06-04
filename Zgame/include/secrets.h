#ifndef SECRET_H
#define SECRET_H

#include <string>

namespace Game {
    class Secret {
    public:
        Secret(int value);
        int getSecretValue() const; // Declare the accessor function as public
    private:
        int secretValue;
    };
}

#endif //SECRET_H

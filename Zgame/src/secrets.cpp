#include "secrets.h"

namespace Game {
    Secret::Secret(int value) : secretValue(value) {}

    int Secret::getSecretValue() const {
        return secretValue;
    }
}

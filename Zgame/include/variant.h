// variant.h
#ifndef VARIANT_H
#define VARIANT_H

namespace Game {

    union Variant {
        int i;
        double d;
        char c;

        Variant() : i(0) {} // Default constructor initializes the int member
        Variant(int val) : i(val) {}
        Variant(double val) : d(val) {}
        Variant(char val) : c(val) {}
    };

} // namespace Game

#endif // VARIANT_H

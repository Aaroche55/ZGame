#ifndef ADVANCED_PREPROCESSOR_H
#define ADVANCED_PREPROCESSOR_H

#define DEBUG 1

#if DEBUG
#define LOG(x) std::cout << x << std::endl
#else
#define LOG(x)
#endif

#endif // ADVANCED_PREPROCESSOR_H

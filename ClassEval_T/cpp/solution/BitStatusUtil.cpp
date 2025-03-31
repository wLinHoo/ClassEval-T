
#include <vector>
#include <string>
#include <stdexcept>  

class BitStatusUtil {
public:
    static int add(int states, int stat);
    static bool has(int states, int stat);
    static int remove(int states, int stat);
    static void check(const std::vector<int>& args);

    BitStatusUtil() = default; 
};


int BitStatusUtil::add(int states, int stat) {
    check({ states, stat });
    return states | stat;
}


bool BitStatusUtil::has(int states, int stat) {
    check({ states, stat });
    return (states & stat) == stat;
}


int BitStatusUtil::remove(int states, int stat) {
    check({ states, stat });
    if (has(states, stat)) {
        return states ^ stat;
    }
    return states;
}


void BitStatusUtil::check(const std::vector<int>& args) {
    for (int arg : args) {
        if (arg < 0) {
            throw std::invalid_argument(std::to_string(arg) + " must be greater than or equal to 0");
        }
        if (arg % 2 != 0) {
            throw std::invalid_argument(std::to_string(arg) + " not even");
        }
    }
}

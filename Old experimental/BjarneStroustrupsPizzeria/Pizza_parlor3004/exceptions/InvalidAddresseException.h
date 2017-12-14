#ifndef INVALIDADDRESSEEXCEPTION_H
#define INVALIDADDRESSEEXCEPTION_H

#include <string>

using namespace std;

class InvalidAddresseException {
    public:
        InvalidAddresseException(int err);
        string get_err();

    private:
        int error;
};

#endif // INVALIDADDRESSEEXCEPTION_H

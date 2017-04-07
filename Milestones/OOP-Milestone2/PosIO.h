#ifndef ICT_POSIO_H__
#define ICT_POSIO_H__
// includes go here
#include <fstream>
#include <iostream>
#include "MyFile.h"

namespace ict {
class PosIO {
   public:
    std::fstream& save(std::fstream& file) const { return file; }
    std::fstream& load(std::fstream& file) { return file; }
    std::ostream& write(std::ostream& os, bool linear) const { return os; }
    std::istream& read(std::istream& is) { return is; }
};
}
#endif

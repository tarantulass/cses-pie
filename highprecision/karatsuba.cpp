#include <pybind11/pybind11.h>
double add(double a,double b){ return a+b; }

namespace py = pybind11;
PYBIND11_MODULE(mylib,m){
    m.def("add",&add);
}

#include <pybind11/pybind11.h>
using namespace pybind11::literals;
namespace py = pybind11;

int add(int i = 1, int j = 2){
    return i + j;
}

PYBIND11_MODULE(example, m){
    m.doc() = "pybind11 example plugin"; // optional module docstring
    m.attr("the_answer") = 42;
    py::object world = py::cast("World");
    m.attr("what") = world;

    m.def("add", &add, "i"_a=1, "j"_a=2);
}

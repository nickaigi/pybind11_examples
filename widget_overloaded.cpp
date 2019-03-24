#include <pybind11/pybind11.h>

namespace py = pybind11;

struct Widget{
    int foo(int x, float y);
    int foo(int x, float y) const;
};

PYBIND11_MODULE(widget_overloaded, m){
    py::class_<Widget>(m, "Widget")
        .def("foo_mutable", py::overload_cast<int, float>(&Widget::foo))
        .def("foo_const", py::overload_cast<int, float>(&Widget::foo, py::const_));
}

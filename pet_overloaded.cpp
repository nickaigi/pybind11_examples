#include <pybind11/pybind11.h>

namespace py = pybind11;

struct Pet {
    Pet(const std::string &name, int age): name(name), age(age) {}

    void set(int age_) {age = age_; }
    void set(const std::string &name_) { name = name_; }

    std::string name;
    int age;
};


//PYBIND11_MODULE(pet_overloaded, m){
//    py::class_<Pet>(m, "Pet")
//        .def(py::init<const std::string &, int>())
//        .def("set", (void (Pet::*)(int)) &Pet::set, "Set the pet's age")
//        .def("set", (void (Pet::*)(const std::string &)) &Pet::set, "Set the pet's name");
//}


/*******************************/
// C++ 14 syntax below: use the -std=c++14
//
// $ c++ -O3 -Wall -shared -std=c++14 -fPIC `python3 -m pybind11 --includes` pet_overloaded.cpp -o pet_overloaded`python3-config --extension-suffix`
//
/*******************************/
PYBIND11_MODULE(pet_overloaded, m){
    py::class_<Pet>(m, "Pet")
        .def(py::init<const std::string &, int>())
        .def("set", py::overload_cast<int>(&Pet::set), "Set the pet's age")
        .def("set", py::overload_cast<const std::string &>(&Pet::set), "Set the pet's name");
}

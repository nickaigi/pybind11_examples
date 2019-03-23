#include <pybind11/pybind11.h>

namespace py = pybind11;

struct Person {
    Person(const std::string &name, const int &age): name(name), age(age){}
    void setName(const std::string &name_) { name = name_;}
    void setAge(const int &age_) { age = age_;}
    const std::string &getName() const { return name; }
    const int &getAge() const { return age; }

    std::string name;
    int age;
};

PYBIND11_MODULE(person, m){
    py::class_<Person>(m, "Person")
        .def(py::init<const std::string &, const int &>())
        .def_readwrite("name", &Person::name)
        .def_readwrite("age", &Person::age)
        .def("setName", &Person::setName)
        .def("getName", &Person::getName)
        .def("setAge", &Person::setAge)
        .def("getAge", &Person::getAge)
        .def("__repr__",
            [](const Person &a){
                return "<person.Person named '" + a.name + "' aged '" + std::to_string(a.age) + "'>";
            }
        );       
}


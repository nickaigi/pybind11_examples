## Examples from pybind11 docs

- How to expose `c++` code to python


### To compile the code

    $ c++ -O3 -Wall -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` file_name.cpp -o file_name`python3-config --extension-suffix`



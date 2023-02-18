g++ --version

# create build directory
mkdir ./build
cd ./build

# compile
## core
g++ -std=c++11 -c ../src/core/*.cpp

## main
g++ -std=c++11 -c ../main.cpp

# link
g++ *.o

# run
./a.out

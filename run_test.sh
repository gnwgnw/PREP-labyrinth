mkdir -p build || exit 1
cd build
cmake .. || exit 1
make VERBOSE=1 V=99 || exit 1
./labyrinth ../test_lab.txt

cmake -S . -B build -G "MinGW Makefiles"
cmake --build build -j
./build/openpigeonqt.exe

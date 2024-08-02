cmake -DCMAKE_CXX_FLAGS="-O3 -fPIC --acpp-targets=omp" -DCMAKE_CXX_COMPILER="${ACPP_PATH}" -S . -B build
cd build
make



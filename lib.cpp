
#include <sycl/sycl.hpp>
#include <pybind11/pybind11.h>
#include <pybind11/iostream.h>
using u32 =unsigned int;
void test_bug(){

    auto test_kernel = [](sycl::queue &q) {
        sycl::buffer<u32> b(10);

        q.submit([&](sycl::handler &cgh) {
            sycl::accessor acc{b, cgh, sycl::write_only, sycl::no_init};

            cgh.parallel_for(sycl::range<1>{10}, [=](sycl::item<1> i) {
                acc[i] = i.get_linear_id();
            });
        });

        q.wait();

        {
            sycl::host_accessor acc{b, sycl::read_only};
            if (acc[9] != 9) {
                throw std::runtime_error(
                    "The chosen SYCL queue cannot execute a basic kernel");
            }

            std::cout << acc[0] << " " << acc[1] << " " << acc[2] << " " << acc[3] << " " << acc[4] << std::endl;
        }


    };

    sycl::queue q{};
    test_kernel(q);

}

PYBIND11_MODULE(buglib,m){

    m.def("test_bug",&test_bug);

}
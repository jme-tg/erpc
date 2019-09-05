#include "erpc_client_setup.h"
#include "erpc_mbf_setup.h"
#include "erpc_matrix_multiply.h"

#include <stdio.h>
#include <chrono> 
#include <iomanip> 
#include <iostream>

void example_client(void) {

    erpc_mbf_t dynamic_buffer = erpc_mbf_dynamic_init();
    // Initialize client running over TCP.
    #if 1
    erpc_client_init(
        erpc_transport_tcp_client_init("192.168.10.159", 6666), dynamic_buffer);
    #else
    erpc_client_init(
        erpc_transport_tcp_client_init("localhost", 6666), dynamic_buffer);
    #endif

    Matrix mat1 = {0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4};
    Matrix mat2 = {0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4};
    Matrix mat3 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    //Do stuff
    printf("doing matrix multiplication on remote x 100\n");
    auto start = std::chrono::high_resolution_clock::now();
	std::ios_base::sync_with_stdio(false);

    for(int i = 0;i < 1000; i++) {
        erpcMatrixMultiply(mat1, mat2, mat3);
    }
    auto end = std::chrono::high_resolution_clock::now();
    double time_taken =
		std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    std::cout << std::endl << "Time taken by " << 1000 << " operations: " << std::fixed
		<< time_taken << std::setprecision(9);
	std::cout << " sec" << std::endl;

    erpc_client_deinit();
}

int main(void) {
    example_client();
    return 0;
}

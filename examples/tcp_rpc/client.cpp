#include "erpc_client_setup.h"
#include "erpc_mbf_setup.h"
#include "erpc_matrix_multiply.h"

#include <stdio.h>

void example_client(void) {

    erpc_mbf_t dynamic_buffer = erpc_mbf_dynamic_init();
    // Initialize client running over TCP.
    erpc_client_init(
        erpc_transport_tcp_client_init("localhost", 6666), dynamic_buffer);

    Matrix mat1 = {0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4};
    Matrix mat2 = {0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4};
    Matrix mat3 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    //Do stuff
    printf("doing matrix multiplication on remote\n");
    erpcMatrixMultiply(mat1, mat2, mat3);
}

int main(void) {
    example_client();
    return 0;
}
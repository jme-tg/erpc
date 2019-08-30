#include "erpc_server_setup.h"
#include "erpc_mbf_setup.h"
#include "erpc_matrix_multiply_server.h"

#include <stdio.h>

// Implement the remote function.
//void set_led(LEDName whichLed, bool onOrOff) {
    // implementation goes here
//}

void example_server(void) {

    erpc_mbf_t dynamic_buffer = erpc_mbf_dynamic_init();
    // Initialize server running over UART.
    erpc_server_init(
        erpc_transport_tcp_server_init("localhost", 6666), dynamic_buffer);

    // Add the IO service.
    erpc_add_service_to_server(create_MatrixMultiplyService_service());

    // Run the server.
    erpc_server_run();
}

int main(void) {
    printf("Starting matrix multiplication server.\n");
    example_server();
    return 0;
}
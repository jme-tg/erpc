#include "erpc_client_setup.h"
#include "erpc_mbf_setup.h"

// Implement the remote function.
//void set_led(LEDName whichLed, bool onOrOff) {
    // implementation goes here
//}

void example_server(void) {

    erpc_mbf_t dynamic_buffer = erpc_mbf_dynamic_init();
    // Initialize server running over UART.
    erpc_client_init(
        erpc_transport_tcp_client_init("localhost", 6666), dynamic_buffer);

    //Do stuff
}

int main(void) {
    example_server();
    return 0;
}
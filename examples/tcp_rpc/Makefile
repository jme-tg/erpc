CXXFLAGS ?= -I../../erpc_c/setup -I../../erpc_c/infra -I../../erpc_c/port -I../../erpc_c/config -I../../erpc_c/transports -g
LDFLAGS ?= -pthread

.PHONY: all
all: server client

server: server.cpp
	g++ $(CXXFLAGS) $(LDFLAGS) server.cpp ../../erpc_c/setup/erpc_setup_mbf_dynamic.cpp \
	../../erpc_c/setup/erpc_setup_tcp_server.cpp ../../erpc_c/setup/erpc_server_setup.cpp ../../erpc_c/infra/erpc_server.cpp \
	../../erpc_c/infra/erpc_crc16.cpp ../../erpc_c/infra/erpc_message_buffer.cpp ../../erpc_c/transports/erpc_tcp_transport.cpp \
	../../erpc_c/infra/erpc_framed_transport.cpp ../../erpc_c/port/erpc_threading_pthreads.cpp ../../erpc_c/infra/erpc_basic_codec.cpp \
	../../erpc_c/infra/erpc_simple_server.cpp erpc_matrix_multiply_server.cpp matrix_multiply.cpp -o $@

client: client.cpp
	g++ $(CXXFLAGS) $(LDFLAGS) client.cpp ../../erpc_c/setup/erpc_setup_mbf_dynamic.cpp \
	../../erpc_c/setup/erpc_setup_tcp_client.cpp ../../erpc_c/setup/erpc_client_setup.cpp ../../erpc_c/infra/erpc_client_manager.cpp \
	../../erpc_c/infra/erpc_crc16.cpp ../../erpc_c/infra/erpc_message_buffer.cpp ../../erpc_c/transports/erpc_tcp_transport.cpp \
	../../erpc_c/infra/erpc_framed_transport.cpp ../../erpc_c/port/erpc_threading_pthreads.cpp ../../erpc_c/infra/erpc_basic_codec.cpp \
	erpc_matrix_multiply_client.cpp -o $@

clean :
	rm client server
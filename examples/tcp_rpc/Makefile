CXXFLAGS ?= -I../../erpc_c/setup -I../../erpc_c/infra -I../../erpc_c/port -I../../erpc_c/config -I../../erpc_c/transports
LDFLAGS ?= -pthread

.PHONY: all
all: server client

server: server.cpp
	g++ -std=c++11 $(CXXFLAGS) $(LDFLAGS) server.cpp ../../erpc_c/setup/erpc_setup_mbf_dynamic.cpp \
	../../erpc_c/setup/erpc_setup_tcp_server.cpp ../../erpc_c/setup/erpc_server_setup.cpp ../../erpc_c/infra/erpc_server.cpp \
	../../erpc_c/infra/erpc_crc16.cpp ../../erpc_c/infra/erpc_message_buffer.cpp ../../erpc_c/transports/erpc_tcp_transport.cpp \
	../../erpc_c/infra/erpc_framed_transport.cpp ../../erpc_c/port/erpc_threading_pthreads.cpp ../../erpc_c/infra/erpc_basic_codec.cpp \
	../../erpc_c/infra/erpc_simple_server.cpp -o $@

client: client.cpp
	g++ -std=c++11 $(CXXFLAGS) $(LDFLAGS) client.cpp ../../erpc_c/setup/erpc_setup_mbf_dynamic.cpp \
	../../erpc_c/setup/erpc_setup_tcp_client.cpp ../../erpc_c/setup/erpc_client_setup.cpp ../../erpc_c/infra/erpc_client_manager.cpp \
	../../erpc_c/infra/erpc_crc16.cpp ../../erpc_c/infra/erpc_message_buffer.cpp ../../erpc_c/transports/erpc_tcp_transport.cpp \
	../../erpc_c/infra/erpc_framed_transport.cpp ../../erpc_c/port/erpc_threading_pthreads.cpp ../../erpc_c/infra/erpc_basic_codec.cpp \
	-o $@
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {
    const int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        std::cerr << "Socket creation error" << std::endl;
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, reinterpret_cast<struct sockaddr *>(&server_address), sizeof(server_address)) < 0) {
        std::cerr << "Socket to port binding error" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "server is running and bound to port 8080" << std::endl;
    close(server_socket);
    return EXIT_SUCCESS;
}

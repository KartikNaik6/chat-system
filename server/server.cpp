#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

int main() {
//what is a socket?: kernal managed endpoint 
    int server_fd = socket(AF_INET, SOCK_STREAM, 0); //variable accepting file descriptor as an integer in return type

    if (server_fd < 0) {
        std::cerr << "Socket creation failed\n";
        return 1;
    }

    std::cout << "Socket created\n";

    return 0;
}
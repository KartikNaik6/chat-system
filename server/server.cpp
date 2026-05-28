#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

int main() {
    //what is a socket?: kernal managed endpoint 
    int server_fd = socket(AF_INET, SOCK_STREAM, 0); //variable accepting file descriptor as an integer in return type
    sockaddr_in server_addr{}; //kernal expects struct variable
    server_addr.sin_family = AF_INET;    
    server_addr.sin_port = htons(8080);  
    server_addr.sin_addr.s_addr = INADDR_ANY;

    //socket() asks kernal to create a socket for it which speaks IPv4 (AF_NET) and is stream oriented (SOCK_STREAM)
    //in linux everything is treated as a stream hence file descriptors are used
    if (server_fd < 0) {
        std::cerr << "Socket creation failed\n";
        return 1;
    }
    //error handling
    std::cout << "Socket created\n";


    bind(server_fd, (sockaddr*)&server_addr, sizeof(server_addr)); // bind the socket and address structure
    listen(server_fd,5);

    int client_socket = accept(server_fd, nullptr, nullptr);  //it also gives client port and IP which we do not need for now that's why nullptr
    //above line is also sufficient to remove the dumb fix(infinite loop)
    std::cout << "client socket created\n";

    //actual communication 
    char buffer[1024]={0};
    recv(client_socket, buffer, sizeof(buffer),0); //server now ready to receive bytes from client_socket and store into buffer
    std::cout<<"client sent: "<<buffer<<"\n";   

    //server's response
    const char* reply = "this is sent back by server";
    int bytes_sent = send(client_socket, reply, strlen(reply), 0);
    std::cout << "Bytes sent: " << bytes_sent << "\n";    
    return 0;
}
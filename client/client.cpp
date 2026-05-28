#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <thread>

void receive_messages(int sock){
    char buffer[1024]={0};
//instead within the main loop made receiving as another function and running it simultaneously using threading 
    while(true){
        int bytes_received = recv(sock, buffer, sizeof(buffer), 0);

        if(bytes_received<=0){
            std::cout<<"Disconnected from the server\n ";
            break;
        }
        std::cout<<"server's response:"<<buffer<<"\n";
    }
}

int main() {

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        std::cerr << "Socket creation failed\n";
        return 1;
    }

    sockaddr_in server_addr{}; //server structure details so that client can connect with the server using connect
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);

    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr); //kernal handles addresses in binary format so to convert IPv4 from human readable format to binary
    
    int connection_status = connect(sock, (sockaddr*)&server_addr, sizeof(server_addr)); //actul connection with the server
    if(connection_status<0){
        std::cout<<"Connection failed\n";
        return 1;
    }
    std::cout<<"connected to the server!!\n";

    //running the receiver thread
    std::thread receiver(receive_messages,sock);

    // actual communication part
    while(true){
        std::string message;
        std::getline(std::cin,message);

        send(sock, message.c_str(), message.length(),0);
    }
    receiver.join();
    return 0;
}
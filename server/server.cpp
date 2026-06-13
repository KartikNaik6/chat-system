#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <thread>
#include <atomic>

using namespace std;

atomic<bool> running(true);

void receive_messages(int client_socket){
    char buffer[1024]={0};
    while(true){
        int bytes_received=recv(client_socket, buffer, sizeof(buffer),0); //server now ready to receive bytes from client_socket and store into buffer

        if(bytes_received<=0){
            cout<<"client disconnected";
            running = false;      //shared flag between main and this thread (thread comms using shared memory)
            break;
        }
        
        cout<<"client sent: "<<buffer<<"\n"; 
    }
}

void handle_client(int client_socket) {
    thread receiver(receive_messages, client_socket);

    while(running){
        string reply;
        getline(cin,reply);// all the client threads would try to read from this same line

        int bytes_sent = send(client_socket, reply.c_str(), reply.length(),0);
        cout<<"Bytes sen: "<<bytes_sent<<"\n";
    }
    receiver.join();
}

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
        cerr << "Socket creation failed\n";
        return 1;
    }
    //error handling
    cout << "Socket created\n";


    bind(server_fd, (sockaddr*)&server_addr, sizeof(server_addr)); // bind the socket and address structure
    listen(server_fd,5);

    int client_socket = accept(server_fd, nullptr, nullptr);  //it also gives client port and IP which we do not need for now that's why nullptr
    //above line is also sufficient to remove the dumb fix(infinite loop)
    cout << "client socket created\n";

    thread receiver(receive_messages,client_socket);

    //actual communication 
    handle_client(client_socket); //moved this big code into a function

    return 0;
}
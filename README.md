# TCP Chat System

A client-server chat application developed in C++ using TCP sockets and multithreading. The project demonstrates core networking concepts such as socket programming, connection management, concurrent communication, and thread synchronization.

## Features

* TCP-based client-server communication
* Real-time message exchange
* Concurrent sending and receiving using threads
* Connection establishment and disconnect handling
* Shared state management using atomic variables
* Linux socket programming APIs

## Technologies Used

* C++
* POSIX Sockets
* Multithreading (`std::thread`)
* Atomic Variables (`std::atomic`)
* Linux Networking APIs

## Project Structure

client.cpp

* Creates a TCP client socket
* Connects to the server
* Runs a dedicated receiver thread
* Sends user messages to the server

server.cpp

* Creates and binds a TCP server socket
* Listens for incoming connections
* Accepts client connections
* Handles message transmission and reception

## Networking Concepts Demonstrated

* TCP Communication
* Client-Server Architecture
* Socket Programming
* Concurrency
* Multithreading
* Synchronization
* Connection Lifecycle Management

## How to Build

Compile the server:

```bash
g++ server.cpp -o server -pthread
```

Compile the client:

```bash
g++ client.cpp -o client -pthread
```

## How to Run

Start the server:

```bash
./server
```

Start the client in another terminal:

```bash
./client
```

The client connects to the server running on `127.0.0.1:8080`.

## Current Limitations

* Supports a single active client connection
* No message encryption
* No user authentication
* No persistent message storage

## Future Improvements

* Multiple client support
* End-to-end encryption
* User authentication
* Group chat functionality
* Improved logging and error handling

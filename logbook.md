#may 25-26
-started project 
-created a **socket**

#may 26-26
-created socket structure and bound it to socket
-made that socket ready for **TCP connections** using listen
-debug- found that when program eventually reaches return 0 after listen it force shuts the running program and sockets are closed; did a dumb fix with never ending loop.

#may 27-26
-added accept() which takes the connnection request from the queue of listen() and gives it its own socket
-created a test client added structure details of server within client code to help client connect with the server
-connected to server using connect()
-using send receive to actually communicate 
-one lesson: add lines to check for errors - would be very helpful for late to debug

#may 28-26
-added infinite looping for turn based communication and replaced hardcoded messages with dynamic ones 
-used **threads** to run receiver and sender functions concurrently this replaces turn based communication with real time communication

#may 29-26
-added atomic library to notify main thread about the disconnect of receiver thread

#june 13-26
-shifting the single client-server chat-system to multi-client-server chat-system using **thread-per-client** approach
-also added line using namespace std to avoid using std:: every time when calling std function (but for large codebases this may cause collissions between functions)
-gave the actual communication with the client in the server it's own function



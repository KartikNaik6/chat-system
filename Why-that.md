socket(): asks kernal to create a socket for the calling program; on error returns negative value
AF_INET: tells that the socket communicates in IPv4 format
SOCK_STREAM: tells that the socket is communicating in TCP (stream-oriented)
sockaddr_in: sockaddr specifies internet socket address for IPv4 and _in stands for internet; this is in struct format because kernal is mainly coded in C and expects predictable fields and fixed memory layouts; infront of this is just a variable, {} specifies that all the fields are initialised to 0
htons(): makes sure that byte order is big endian msb first then lsb; this is the universal byte ordering standard, networking convention; this stands for host to network short (16 bits)
INADDR_ANY: kernal takes this as 0.0.0.0 which actively listens to all the interfaces on the device (lan, localhost, ethernet etc)
bind(): binds socket and structure 
sockaddr*: why not sockaddr_in*? because kernal API is generic: so use sockaddr*
listen(): is what tells kernal that this socket is ready for incoming connections (TCP in this case); incoming connections enter pending queue
accept(): accept returns the connected socket after TCP handshake; kernal handles tcp handshake itself
inet_pton(): human readable IP string to binary representation (presentation -> network); because kernal internally uses binary representation 
connect(): similar to bind but bind tells that the calling function owns the structure details while connect asks kernal to establish a connection with the server structure details attached to client code
recv(): this is to make the process ready for incoming bytes 
send(): tells kernal to copy these bytes into TCP send buffer and transmit them; note sending and receiving can be done at same socket since the mode of communication is full duplex
c_str(): this converts cpp string to c style string pointer (kernal purposes)

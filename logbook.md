may 25-26
started project 
created a socket

may 26-26
created socket structure and bound it to socket
made that socket ready for TCP connections using listen
debug- found that when program eventually reaches return 0 after listen it force shuts the running program and sockets are closed; did a dumb fix with never ending loop.

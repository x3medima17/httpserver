# Socket File Transfer


Repository link: https://github.com/x3medima17/socket

This is an implemetation of ASCII file transmission through sockets, written for Network Programming course, KAIST .

The folowing 'tools' were used.
  - Object-Oriented Programming
  - Tests
  - Continuous Integration
  - Github
  - Ubuntu 16.04 server
  - Vim 


 
Instalation
-----------

First of all clone or download this repository.
~~~ sh
$ git clone https://github.com/x3medima17/socket
~~~

Then make project, all executable files will be placed in `bin` folder.
~~~ sh
$ make
~~~

Usage
-----
To use it you need to start two processes, one for `client` and another one for `server`.
Server accepts only one argument, port to run on. Ex:
~~~ sh
$ ./server 8080
~~~

Client is a little bit more complex, it takes three arguments: host, port, file to send. Ex:
~~~ sh
$ ./client localhost 8080 file.txt
~~~
It will create file `out.txt`, identical to `file.txt`.


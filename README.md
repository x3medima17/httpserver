# Socket File Transfer

[![Build Status](https://travis-ci.org/x3medima17/DoublyLinkedList.svg?branch=dev)](https://travis-ci.org/x3medima17/DoublyLinkedList)


This is an implemetation of ASCII file transmission through sockets, written for Network Programming course, KAIST .

The folowing 'best practices' were used.
  - Object-Oriented Programming
  - Header Files
  - Tests
  - Continuous Integration
  - Github

 
Instalation
-----------

First of all clone or download this repository.
~~~ sh
$ git clone https://github.com/x3medima17/socket
~~~

Then make project.
~~~ sh
$ make
~~~

Using
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



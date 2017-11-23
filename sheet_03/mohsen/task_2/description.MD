#Adapter
abstract:

Convert the interface of a class into another interface clients expect. Adapter lets classes
work together that couldn't otherwise because of incompatible interfaces.

Motivation:

assume for example you are dealing with a certain API, the client already exsisting code needs the factionality of this API, but
in compatiable with it, think of an API to calculate the area of geometrical shapes, the API deals with Mile as unit of measure 
the client deals with Meter


#Abstract:

In class-based programming, the factory method pattern is a creational pattern that uses factory methods to deal with the problem of creating objects without having to specify the exact class of the object that will be created. This is done by creating objects by calling a factory method—either specified in an interface and implemented by child classes, or implemented in a base class and optionally overridden by derived classes—rather than by calling a constructor.

Motivation:

Think of an application, for example shop to sell pets, they pets inhert from a class animals, 
as a client for this application instead of caring about creating those objects seperately, one can deal with it through 
a single method that return the "suitable","wanted" type of animalss


#State

Abstract:

Allow an object to alter its behavior when its internal state changes. The object will
appear to change its class.


Motivation:

think of an application, where the state of the object changes by a certain action, this matches
the concept of finite state automata.



#Front Controller Design Pattern

The front controller design pattern means that all requests that come for a resource in an application will be handled by a single handler and then dispatched to the appropriate handler for that type of request. The front controller may use other helpers to achieve the dispatching mechanism.


#Object Pool

Intent:

Object pooling can offer a significant performance boost, it is most effective in situations where the cost of initializing a class instance is high, the rate of instantiation of a class is high, and the number of instantiations in use at any one time is low.


#Event based asynchronous

if the program have a long running operation, the event base asynchronous can execute this operation in the background "working thread"
this has the benifit of allowing the program to continue execution without the need for waiting for a such long running task.




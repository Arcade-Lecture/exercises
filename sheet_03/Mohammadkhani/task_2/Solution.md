##### 1. Chose one creational pattern, describe it and give an UML representation!
**Answer**: I've chosen **_"factory method"_**. the factory method pattern is a creational pattern that uses factory methods to deal with the problem of creating objects without having to specify the exact class of the object that will be created. This is done by creating objects by calling a factory method—either specified in an interface and implemented by child classes, or implemented in a base class and optionally overridden by derived classes—rather than by calling a constructor.

Creating an object often requires complex processes not appropriate to include within a composing object. The object's creation may lead to a significant duplication of code, may require information not accessible to the composing object, may not provide a sufficient level of abstraction, or may otherwise not be part of the composing object's concerns. The factory method design pattern handles these problems by defining a separate method for creating the objects, which subclasses can then override to specify the derived type of product that will be created. The factory method pattern relies on inheritance, as object creation is delegated to subclasses that implement the factory method to create objects.

Factory Method is to creating objects as Template Method is to implementing an algorithm. A superclass specifies all standard and generic behavior (using pure virtual "placeholders" for creation steps), and then delegates the creation details to subclasses that are supplied by the client.

Factory Method makes a design more customizable and only a little more complicated. Other design patterns require new classes, whereas Factory Method only requires a new operation.

People often use Factory Method as the standard way to create objects; but it isn't necessary if: the class that's instantiated never changes, or instantiation takes place in an operation that subclasses can easily override (such as an initialization operation).

##### 2. Chose one structural pattern, describe it and give an UML representation!
**Answer**: I've Chosen **_"Adaptar method"_**. the adapter pattern is a software design pattern that allows the interface of an existing class to be used as another interface. It is often used to make existing classes work with others without modifying their source code.

An adapter allows two incompatible interfaces to work together. This is the real-world definition for an adapter. Interfaces may be incompatible, but the inner functionality should suit the need. The Adapter design pattern allows otherwise incompatible classes to work together by converting the interface of one class into an interface expected by the clients.

##### 3. Chose one behavioral pattern, describe it and give an UML representation!
**Answer:** I've chosen **_"State Pattern"_**. The state pattern is a behavioral software design pattern that implements a state machine in an object-oriented way. With the state pattern, a state machine is implemented by implementing each individual state as a derived class of the state pattern interface, and implementing state transitions by invoking methods defined by the pattern's superclass.
The state pattern can be interpreted as a strategy pattern which is able to switch the current strategy through invocations of methods defined in the pattern's interface.

##### 4. Chose one concurrency pattern, describe it and give an UML representation!
**Answer:** I've chosen **"event-based asynchronous pattern"**. it is a design pattern in which the call site is not blocked while waiting for the called code to finish. Instead, the calling thread is notified when the reply arrives. Polling for a reply is an undesired option. 
The Event-based Asynchronous Pattern makes available the advantages of multithreaded applications while hiding many of the complex issues inherent in multithreaded design. Using a class that supports this pattern can allow you to:
- Perform time-consuming tasks, such as downloads and database operations, "in the background," without interrupting your application.
- Execute multiple operations simultaneously, receiving notifications when each completes.
- Wait for resources to become available without stopping ("hanging") your application.
- Communicate with pending asynchronous operations using the familiar events-and-delegates model

##### 5. Chose one diverse pattern, describe it and give an UML representation!
**Answer:** I've chosen **"object pool pattern"**. it is a software creational design pattern that uses a set of initialized objects kept ready to use – a "pool" – rather than allocating and destroying them on demand. 
A client of the pool will request an object from the pool and perform operations on the returned object. When the client has finished, it returns the object to the pool rather than destroying it; this can be done manually or automatically.

##### 6. Chose one architectural pattern, describe it and give an UML representation!
**Answer:** I've chosen **"front controller"**. It is "a controller that handles all requests for a website", which is a useful structure for web application developers to achieve the flexibility and reuse without code redundancy.

# _All the UML diagrams will be attached to the directory._

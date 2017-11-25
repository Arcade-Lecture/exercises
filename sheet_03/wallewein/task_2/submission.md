# Task2

## (1) Creational pattern: Singleton-Pattern
The singleton pattern describes that there is only one instance of a class which is used by all referrencing ressources to avoid to create multiple instances of for example large classes. Additionally, it's used to centralize ressources.

![singleton][singleton]

## (2) Structural pattern: Adapter
The adapter pattern is used to convert interfaces to a standardized form which is expected for example from the client. It can be useful for integrating components into different systems without changing them.

![Adapter][adapter]

## (3) Behavorial pattern: State
The state pattern is used to have objects which adapt their behavior to different states. The idea is to avoid big switch cases or if branches using a state interface and some states which implement this one and the corresponding object changes it's state by replacing it's reference to a state instance.

![State][state]

## (4) Concurrency pattern: Event-based asynchronous
To execute parallel tasks or heavy tasks without blocking the UI the event-based asynchronous task can be used. The idea behind this task is to execute a method asynchronous and to receive it's result using a defined Event.

![Event][event]

## (5) Architectural pattern: Front controller
The front controller design pattern is used to provide a centralized request handling mechanism so that all requests will be handled by a single handler. In the following example all request are handled by the BaseRouter and are passed to the added Router matching the context.

![Front controller][front-controller]

## (6) Diverse: Object pool
The object pool pattern is used to avoid creating a new Object for every use. There is an object pool with fixed size of objects and instead of calling a constructor of the class you ask the pool to give you an already existing instance of the class.

![alt text][pool]

[singleton]: singleton.png
[pool]: pool.png
[event]: event.png
[state]: state.png
[adapter]: adapter.png
[front-controller]: front-controller.png

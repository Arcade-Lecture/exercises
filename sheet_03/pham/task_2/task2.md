# Creational Pattern: Singelton Pattern:

	restricts the instantiation of a class to one object
 	useful when exactly one object is needed to coordinate actions across the system
	The concept is sometimes generalized to systems that operate more efficiently when only one object exists, or that restrict the instantiation to a certain number of objects

# Structural Pattern: Bridge Pattern:

	When a class varies often, the features of object-oriented programming become very useful because changes to a program's code can be made easily with minimal prior knowledge about the program.
	The bridge pattern is useful when both the class and what it does vary often.


# Behavioral pattern: Observer Pattern:

	an object, called the subject, maintains a list of its dependents, called observers, and notifies them automatically of any state changes, usually by calling one of their methods.
	The observer pattern is implemented in numerous programming libraries and systems, including almost all GUI toolkits.

# Concurrency pattern: ActiveObject Pattern:

	The reason for using the active object pattern is to introduce concurrency, by using asynchronous method invocation and a scheduler for handling requests.
	The pattern consists of the following elements:
	A proxy, which provides an interface towards clients with publicly accessible methods.
	An interface which defines the method request on an active object.
	A list of pending requests from clients.
	A scheduler, which decides which request to execute next.
	The implementation of the active object method.
	A callback or variable for the client to receive the result.


# diverse pattern: NullObject Pattern:

	The null object pattern describes how to use object with no referenced value or with defined neutral "null" behavior.
	The advantage of this approach over a working default implementation is that a Null Object is very predictable and has no side effects: it does nothing.
	For example, a function may retrieve a list of files in a folder and perform some action on each.
	In the case of an empty folder, one response may be to throw an exception or return a null reference rather than a list.
	Thus, the code which expects a list must verify that it in fact has one before continuing, which can complicate the design.
	By returning a null object (i.e. an empty list) instead, there is no need to verify that the return value is in fact a list.

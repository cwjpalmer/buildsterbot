# buildsterbot

This library is intended to make building new things with Arduino faster, and easier, for experienced Arduino hackers.

Here's the methodology:

1. Beark your desired system down into a series of digital and analog inputs, where possible (servos, buzzers, etc. will remain outside this analysis)
2. Create objects of the appropriate types in an Arduino sketcht. Prototype your system, and build the desired funcitonality.
3. (When helpful) Group your objects. Create new .h and .cpp files that create classes to define recurring groups of objects. Use buildsterbot objects as subobjects. This is key to allow updating various projects from one library update.

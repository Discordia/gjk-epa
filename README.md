Prototype C++ implementation of GJK and EAP algorithms for 2D collision detection

Basically a direct (but a bit simplified) port of GJK and EAP in dyn4j. See: https://github.com/wnbittle/dyn4j and http://www.dyn4j.org.

*Work In Progress!* It is starting to work, not very well tested though. 

I have done some successful tests with collision detection between triangle, rectangle, polygon and circle. 

BUG: There are cases when the algorithm just hangs, i.e. iterates for ever.

Dependencies
=========================================
GLM for vector and matrix math, see: http://glm.g-truc.net/0.9.7/index.html

Build
=========================================
git submodules init </br>
giut submodules update </br>
mkdir build </br>
cd build/ </br>
cmake .. </br>
make -j8

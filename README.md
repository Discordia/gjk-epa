C++ implementation of GJK and EPA algorithms for 2D collision detection

Basically a direct (but a bit simplified) port of GJK and EPA in dyn4j. See: https://github.com/wnbittle/dyn4j and http://www.dyn4j.org.

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

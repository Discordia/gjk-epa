Prototype C++ implementation of GJK and EAP algorithms for 2D collision detection

Basically a direct (but a biut simplified) port of GJK and EAP in dyn4j. See: https://github.com/wnbittle/dyn4j and dyn4j.org.

*Work In Progress!* Nothing is really working as of this moment!!!

Dependencies
=========================================
GLM for vector and matrix math, see: http://glm.g-truc.net/0.9.7/index.html

Build
=========================================
git submodules init
giut submodules update
mkdir build
cd build/
cmake ..
make -j8

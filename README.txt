Compiling in Visual Studio (2012)
--------------------------

Is pretty straight forward. Open in VS, open View -> Other Windows ->
Property Manager. Modify SDL and SDL_image sheets to point to your
locations for the includes and libraries (available under VC++
Directories in the property pages).



Compiling on linux
------------------

First make sure you have SDL and SDL_image installed (including
development packages, usually named -dev or similar). Then open a
terminal, cd into the LD26 subdirectory and run make.

If you get an error about '-std=c++11', edit the Makefile and replace
c++11 with c++0x.

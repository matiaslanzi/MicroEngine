# MicroEngine
Small game engine class derived from LittleEngine.
For now is very basic, but it will get you rolling with a decent timing mechanism and delta time in milliseconds.
I will add more functionality shortly, please drop me a line if you have a any questions or suggestions. 
I would love to have another point of view about the timing.

Cheers 
~matiaslanzi

## Implementing
Subclass `mlMicroEngine` class, provide the required virtual functions and that's that.
MicroEngine will create a window and renderer for you as well as provide the timing for the game loop and delta time.

There a are 3 files in the project:

`mlMicroEngine.cpp` is the one to subclass

`Application.cpp` is where you will implement your code

`main.cpp` is the entry point, creates the object and enters the game loop

Take a look at those files, you'll get it right away.


## Compiling
Change the symlinks on the 'includes' folder to point to your SDL2 libraries's includes.
Change the symlinks on the 'lib' folder to point to your SDL2 libraries's libs.
Use make from the project root.

## Dependencies
So far it's using only SDL2, I will add SDL2_mixer, SDL2_image, SDL2_ttf, etc, so make sure you include do your linking.

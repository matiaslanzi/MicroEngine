# MicroEngine
This is a first iteration a basic mini game engine with SDL that can get me going quicly without much fuzz. 
For now is very basic, but it will get you going with a decent timing mechanism and delta time in milliseconds.
I will add more functionality shortly, please drop me a line if you have a any questions or suggestions. 
I would love to have another point of view about the timing.

Cheers 

@matiaslanzi

[www.matiaslanzi.com](https://matiaslanzi.com)


## Implementing
Subclass `mlMicroEngine` class, provide the required virtual functions and that's that.
MicroEngine will create a window and renderer for you as well as provide the timing for the game loop and delta time.

There a are 3 files in the project:

`mlMicroEngine.cpp` is the one to subclass

`Application.cpp` is where you will implement your code and where `main` is located.

Take a look at those files, you'll get it right away.

## Compiling
Change the symlinks on the 'includes' folder to point to your SDL2 libraries's includes.
Change the symlinks on the 'lib' folder to point to your SDL2 libraries's libs.
Use make from the project root.

## Dependencies
So far it's using only SDL2, I will add SDL2_mixer, SDL2_image, SDL2_ttf, etc, so make sure you include do your linking.

## Contributions
Please feel free to contribute to this project.
I marked with `TODO:` the stuff that can be made better and of course any ideas are welcome.
The main idea is to kepp this MicroEngine small.
If you want more bells and whistles please look at [LittleEngine Repository](https://github.com/matiaslanzi/LittleEngine) this is a more complete OO implementation of a simple game angine.

Hope this is as useful for you as it was for me writing it. I claim no status in these programming matters other than longevity. I am just having fun. I love C++ and my only hope is to continue learning. 
Thanks

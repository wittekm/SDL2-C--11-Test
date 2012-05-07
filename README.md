# SDL2 & C++11 test

This is simply me playing around with the new features of C++11 in the context
of a game in SDL1.3 (rechristened SDL2 - think Java 1.5).

## To-do:
* Lambdas!
    Lambdas are cool. **Closures moreso.**
* Figure out a good reason to use transform over for\_each.
* Figure out what the hell this engine is gonna be for. Galaxian or an Advance Wars clone? _Who knows?_

* Eventually abstract out GameObjects into sometihng like Static, Player and NPCGameObject or something. I dunno. In any case NPCGameObject will need to store a Strategy, which I also have to make!
* Eventually make a GameObjectFactory?


## Requirements
* GCC 4.7; not every compiler supports C++11 equally.
* Eclipse 3.7 because I'm too lazy to do a makefile and Xcode 3 doesn't do anything better than GCC 4.2.
* SDL2 as libSDL2.dylib/.so/.a/.dll or what-have-you. I'm using a build from the end February 2012.
* SDL\_image and SDL\_ttf from the SDL Mercurial branch; I'm using builds made on April 10, 2012.

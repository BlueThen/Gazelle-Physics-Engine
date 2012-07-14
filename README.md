# Gazelle #

## Summary ##

Gazelle will be a Verlet Integration based physics engine, implemented in C++ using OpenFrameworks.

Currently I'm learning the works of C++, OpenFrameworks, and github all at once, so bare with me.

If you're experienced, and see me doing anything embarrassingly wrong, feel free to commit-request, or whatever, any suggestions.

## Thanks ##

Special thanks to some folk at #reddit-gamedev irc.freenode.net

In no particular order: kiwibonga, noct, Murarth, mrbushido, _jonathan

I may have missed some of the names from the tag team that took on my myriad of problems.


## Status Updates ##

### July 14, 2012

Gazelle is now an interactive fabric simulator. Next we'll be adding some stability by implementing a proper timestep.

### July 13, 2012 ###

Fully implemented links... named it PMLinks because one of the errors earlier made it seem like it was conflicting with something else in the system named "Link." Instead, it was because I didn't have a default constructor (that's required!?).

Ran into a lot of confusion about references, pointers, vectors, arrays, and what-have-nots. From the looks of it, I'll need to construct some safety nets to handle some of the potential adding and removal of pointmasses, and the re-allocation of elements in my vectors.

### July 12, 2012 ###

Computer had troubles handling Visual Studio 2010. 

Running CCleaner and Defraggler to hopefully speed things up, somewhat.

Still feel pretty awkward with C++. Pointers/Addresses is a nice added level of control, but are still awkward for me.

I began the implementation of Link constraints. 

Had to quit early after some frustrations with VS 2010, and computer freezing at inconvenient times.
     
     
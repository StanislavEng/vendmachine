# Vending Machine Program
### Used to repractice C++ programming

Have not worked in C++ (or any programming outside of embedded) environments in a while. 
This project is meant to create a simple program that can be developed to be more encompassing
the most useful features of C++, from structs to classes, to pointers, etc.

This project is a two parter: an administration software for deploying, managing, stocking, etc.,  
of vending machines in various environments (currently offices and uni). This side allows for  
control of all of the parts from naming it, renaming, changing quantity and item variety, etc.  
THe other part is the user side, where users can input money into the machine and then select a  
food or drink item. The machine will track how much you put in, and as well as total lifetime profit. 

This was done in the order of learning I remember from school, which is inefficient code wise, but  
allows me to better learn and understand the concepts and how things work.

## Roadmap:

### Stage 1:
The original program, using one .cpp file with structures only.
#### Rev 1 --> Main is main
This revision of the code had me writing almost the entirety of the code in the main body function.  
This also involved me attempting to use struct to keep track of the machines.  
I hated this, it was really annoying and bad and I gave up at a reasonable time to move on 
(I hope I don't have it saved here, maybe at an early commit)
#### Rev 2 --> functional programming
This is where I swapped to a test driven development step I learned earlier on: 
main body introduces the code and the rest of the operation happens in functions. 
I swapped to using pointers and structs (really helpful in my Arduino EEPROM project) which was a very interesting  
learning experience and a lot of struggles. The majority of the logistics control part should be finished. 
Just need the user side vending machine usage code. 

### Stage 2:
Converting to Classes and maybe vectors.

### Stage 3: 
File I/O to save the machines so I don't have to keep adding and QT GUI

### Stage 4:
TBD

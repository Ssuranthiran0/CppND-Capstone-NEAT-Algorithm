# CPPND: Capstone Project Repo

This is my capstone project for the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213).

Cloned from https://github.com/Udacity/CppND-Capstone-Hello-World starter code provided by Udacity.

## Overview of Project
For this project, I have chosen to implement a basic neural network using a modified version of the NEAT algorithm. The NEAT (NeuroEvolution of Augmenting Topologies) algorithm is an algorithm for generating a neural network. Each network consists of nodes, which are separated into different layers, and connections between the nodes. When training, each 'generation' is tested for the problem trying to be solved, and gets assigned a score based on the network's performance. At the beginning of the next generation, all but the best performing generation get removed, and, along with the best performing network of the previous generation, a fixed amount of copies are made of that network. These copies, however, have slight mutations, such as changing the properties of specific nodes, adding new connections between nodes, and even adding more nodes. Eventually, as more and more generations are simulated, the network will get better and better at solving the problem that was being trained for, even if it had not been directly what the problem even was, through the process of natural selection!

For this project, the problem that I have chosen to solve is trying to predict a mathematical equation (ex. y=sinx). One thing I could improve on is the fact that I have designed the Network to be relatively generic in most ways, except for typing. Most or some of the properties and methods of the Network class would need to be altered in some way in order to be used in a different project


## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw-w64.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./NEATAlgorithm`.
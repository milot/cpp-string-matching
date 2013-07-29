String Matching in C++
========================

Introduction
------------

This is a very simple string matching algorithm written in C++ that uses a finite state machine and a trie to do the matching. Furthermore this 
algorithm is based on a paper written in 1975 by Alfred Aho and Margaret J. Corasick. Furthermore this is only a weekend project that I hacked on 
some time ago and never published it, until now.

String Matching Algorithm
---------------------------

This implementation is based on [the original paper published on 1975](http://www.win.tue.nl/~watson/2R080/opdracht/p333-aho-corasick.pdf).

I am using the BFS (Breadth First Search) strategy when building the failures for the string matching index, so I am visiting the neighbours before 
visiting the child nodes using a queue as presented in the original paper.

How the string matching is being performed is best represented in the diagram below taken from [the slides by Pekka 
Kilpeläinen](http://www.cs.uku.fi/~kilpelai/BSA05/lectures/slides04.pdf)

![aho-corasick](http://i.imgur.com/FGivGsS.png)

Trie
-------------------

You'll find the simplest [Trie](http://en.wikipedia.org/wiki/Trie) implementation.

Trie has an ordered tree data structure so in our case it will keep adding characters until it reaches the end of the string that we passed. In the end our tree will look like the diagram below for strings like corvo, hey, his and hers, that's my goal for now but I will keep changing it. You can check the usage in the main.cpp file.

Trie diagram is taken from the same [slides](http://www.cs.uku.fi/~kilpelai/BSA05/lectures/slides04.pdf) as the Aho Corasick diagram.

![trie](http://i.imgur.com/W4nLeCT.png)

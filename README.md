# CSE-310
Data Structure and Algorithms
This repository hold three projects </br>

# Project 1: Major League Baseball

The World Series is the annual championship series of Major League Baseball in North America, contested
since 1903 between the American League champion team and the National League champion team. A
mountain of statistics is gathered for each Major League Baseball (MLB) game, player, player position, and
team. In this project you will write a program that executes a sequence of commands that operate on MLB
game statistics over a number of years. </br>

The format of the input data is as follows:<br>
• The number of years y (integer) of team game statistics in this data set. <br>
• For year y the following is provided:<br>
    <pre>The total number of teams t in MLB for year y.
    For each of the t teams the following statistics are provided in a tab separated list</pre>
    
<p>∗ The team name (string),<br>
∗ the league, either American League (AL) or National League (NL) (string),<br>
∗ the number of games in which a player has appeared (integer),<br>
∗ the number of official at bats by a batter (integer),<br>
∗ the number of runs,<br>
∗ the number of times a batter hits the ball and reaches bases safely,<br>
∗ the number of times a batter hits the ball and reaches second base,<br>
∗ the number of times a batter hits the ball and reaches third base,<br>
∗ the number of home runs,<br>
∗ the number of runs that score safely,<br>
∗ the number of walks by a batter (four balls during an at bat),<br>
∗ the number of strikeouts by a batter,<br>
∗ the number of times a player has stolen a base,<br>
∗ the number of times a player has been put out attempting to steal a base,<br>
∗ the average number of hits by a batter defined by hits divided by at bats,<br>
∗ the on base percentage,<br>
∗ the slugging percentage, and<br>
∗ the on base percentage plus slugging</p>

# Project 2: The myAppStore Application

Applications for mobile phones are available from a variety of online stores, such as iTunes for Apple’s
iPhone, and Google Play for Android phones.
In this project you will write an application called myAppStore. First, you will populate myAppStore
with data on applications under various categories. The data is to be stored simultaneously in both a hash
table, to support fast look-up of an application, and in a search tree to support certain queries.
Once you have populated myAppStore with application data, you will then process queries about the
apps and/or perform updates in your store.

## myAppStore Application Data Format
The myAppStore application must support n categories of applications. Allocate an array of size n of type
struct categories, which includes the name of the category, and a pointer to the root of a search tree
holding applications in that category. That is, there is a separate search tree for each category of applications.
For example, if n = 3, and the three categories are “Games,” “Medical,” and “Social Networking,” then you
are to allocate an array of size 3 of struct categories and initialize each position to the category name
and a a pointer to the root of a search tree for applications in that category (initially nil)

# Project 3: Graphs
Graphs are a pervasive data structure, and algorithms for working with them are fundamental in computer
science. There are a great number of interesting and practical computational problems defined in terms of
graphs. The goal in this project is to implement a few of them. To have more chance to interpret the results,
we use some real data sets in this project, for example, a social networking data set from Facebook, and
a data set that represents how autonomous systems (ASs) in the internet exchange traffic flows with their
peers, i.e., their neighbours.

### Data Format and Data Sets
##### Adjacency List Graph Representation
In this project, you must use an adjacency list to represent the graph. Such a representation of a graph
G = (V, E) consists of an array A of n = |V | pointers to linked lists, one for each vertex in V . For each
u ∈ V , the adjacency list A[u] contains all the vertices v such that there is an edge (u, v) ∈ E. That is,
A[u] consists of linked list of all the vertices adjacent to u in G. The vertices in each adjacency list are not
ordered.</br>
##### Input Data Format
You must read the input data from standard input (stdin). The data is provided in a file as a convenience;
you should redirect stdin from the file, i.e., do not use any file operations.
The format of the input is as follows:
<pre> 1. First, the the graph G = (V, E) is provided. The first line gives n = |V |, the number of vertices in the
graph. The second line gives m = |E|, the number of edges in the graph. Each of the next m lines
gives an edge e = (u, v) ∈ E specified by its two endpoints, i.e., u, v ∈ {0, 1, . . . , n − 1}. If there are
self-loops, i.e., u = v, do not insert them into the graph.
You should allocate an array of pointers of size n, and initialize each entry in the array to Nil. As
each edge e = (u, v) is processed, insert it into the adjacency list for vertices u and v.
2. Once the graph is initialized, commands to perform analyses of the graph then follow. That is, after
the last edge in the graph, a line with k, the number of commands to execute is given. The subsequent
k lines each has one command.</pre>

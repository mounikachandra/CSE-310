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


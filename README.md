Readability score 
==== 

Application written in C as part of the [![CS50 Badge](https://img.shields.io/badge/-CS50-red)](https://cs50.harvard.edu) class problem sets to grade the readability of different texts.

Table of content
----
* [General info](#general-info)
* [Setup](#setup)
* [Technologies](#technologies)

### General info

Readability grading application written in C. The aim of the program is to grade any texts entered by the user. There are three different outputs of the program depending on the grading index:
 * Before Grade 1
 * The Grade Index
 * Grade 16+ 

The grade is calculated by the Coleman-Liau formula as it follows: 0.0588 * L - 0.296 * S - 15.8, where L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text. 

### Setup

The application can be ran locally or using the [![CS50 Badge](https://img.shields.io/badge/-CS50-red)](https://cs50.harvard.edu) <a href="https://ide.cs50.io">IDE</a> after logging in with your GitHub account.

To run the program:
 1. It needs to be complied: `$ make readability.c`
 2. Started with the selected key as an argument: `$ .Text: "This is an example"`
 3. Enter the text you would like to encrypt: `Grade 16+`
 
### Technologies
 
 Libraries:
 * stdio.h
 * cs50.h
 * string.h
 * ctype.h
 * <img alt="C" src="https://img.shields.io/badge/c%20-%2300599C.svg?&style=for-the-badge&logo=c&logoColor=white"/>

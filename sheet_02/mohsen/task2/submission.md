# Task2 (Git cheatsheet)

a Git every day commands, given as a scenario based approach
before starting make sure that you have git already installed.

## 1.Initiate a local repository

1. you need to create a folder for this repository:

        mkdir mylocrep && cd localrep
        
this will create a folder "localrep" and changes the directory to localrep

2. then this command to create a repository
        
        git init

what this command will do is the following: 

> This command creates an empty Git repository - basically a .git
> directory.

In plain english, think of this .git folder as the database, that will keep track of the updates
that is done to the files with in this repository
          
## 2.Choosing a work flow:

There are many ways you can organize your work when dealing with git, here is a comparission
between different kinds of workflows:


| Workflow      | #remote repositories| #remote branches    | branch lifetime | Merge respon  | advent             | disadven              |
|:-------------:|:-------------------:|:-------------------:|:---------------:|:-------------:|:-----------------: |:---------------------:|
| Centralized   | one                 | at most one         | permenant       | flixible**    |easy to use         |single point of failure|
| Feature branch| one                 | more than one       | permenant       | flixible**    |parallel development|outdated branches      |
| Git Flow      | one                 | more than one       | temporary       | flixible**    |parallel development|bit complex            | 
| Forking       | more than one       | at least one        | depends*        | restricted**  |good for opensource |complex 4 internal proj|

* depends: if you forked from a repository uses gitflow then it will be temporary otherwise it will be permenant. 
* flixible vs restricted: in the forking workflow...changes are made by contributors via pull requestes to be accepted
   by the gate keepers....other workflows doesn't need such restriction.

> How choosing the workload will effect his work?

for example if the remote repository follows centerlized workload, for reasons it is small software project. if my friend will choose git flow layout, it is perfectly fine..but it would be more complex than dealing with the centralized.

> Rule of thumb:

Centralized: small project, single developer maybe.

Feature: small project, more than one developer.

gitflow: medium to large project more than one developer.

forking: open source software.


## 3.Committing one out of two:

Commit A first

    git commit A -m "Add A"

Commit B

    git commit B -m "Add B"

## 4.Ignoring files:

to ignore files locally... assume that the repository is located with in $proj folder
then:

        nano $proj/.git/info/exclude
        
then type the specific format that you want to execlude, to execlude some clion formats type:

        *.cbp
for eclipse type:
        
        *.project

and so one, if you want this changes to be global, then the changes should be made to another file
namely the .gitignore file.
                
                
## 5.Merging vs rebasing:
        
Assume you have Branch A and Branch B,

if you are in A and you want to merge B.... it means it will put the commits from B after the Head of A.
if you are in A and you want to rebase from B ... it means it will put the commits from A after the head of B,
so it rewrites the history.

If you want to "add"  updates from a feature branch to the master branch use merge.
If you want to "add"  updates from the master branch to a feature branch use rebase.


## 6.Rewrite History:

to change the message of the last commit please use:

    git commit --amend -m "New commit message"        

and then push the changes
 
    git push --force origin $branch_name 

if it isn't the last commit, and it isn't the initial "root" commit.

     git reflog 
     
to find the corresponding commit, copy the hash of this commit then

     git rebase -i $commit_hash
     
this will open a file, for the commit we want to work on, modify pick to reword

then modify the message, then push the changes     

    git push --force origin $branch_name
    
if it is the initial commit, then

     git rebase -i --root 
     
and then do the same steps as the previous command

## 7.Stash your work:
simply by using git stach to temporary save our work
   
     git stash

then checkout the branch you want to work on, you can restore the work by switching back to your repository
then restore by
     
     git  stash apply
     
   
                     

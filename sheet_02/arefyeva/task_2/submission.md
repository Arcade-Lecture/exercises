
#### Initializing your own local repository.

First, one needs to create a directory for the future project and go to this directory. From there, the following command has to be run:
`git init`
A .git folder is created in this repository, that stores information about the repository, changes, history etc.
Then, after new files are added to the directory, the user can run `git add <file1> … <fileN>` and `git commit`.
This repository, however, can now be used only locally. To work on a project with other people in a jolly cooperation, this repository needs to be connected to a central repository.

#### Remote repositories & branching workflows.

Here are the differences:

|                                                	| centralized    	| feature branch                            	| GitFlow                                                                                    	| forking                                                  	|
|------------------------------------------------	|----------------	|-------------------------------------------	|--------------------------------------------------------------------------------------------	|----------------------------------------------------------	|
| number of remote repositories                  	| one            	| one                                       	| one                                                                                        	| many                                                     	|
| number of remote branches                      	| one            	| many, one for every feature               	| many                                                                                       	| depends on what workflow  a concrete repository is using 	|
| branches' lifetime                             	| infinite       	| as long as the feature is being developed 	| both infinite (e.g. a branch with  current development) and finite (e.g. feature branches) 	| depends on what workflow  a concrete repository is using 	|
| who merges changes into the official code base 	| all developers 	| all developers                            	| all developers                                                                             	| trusted project maintainers                              	|

Centralized workflow is easy to use, but, in case a commit introduces a bug, the master branch ends up being buggy.
Feature branch workflow allows to keep the master branch free of bugs, introduced by intermediate changes. However, this workflow might slow down the development, because the features need to be reviewed before merging into the master branch.
GitFlow, in general, has the same advantages and disadvantages as the feature branch workflow.
Forking workflow allows to keep the code base safe by not allowing untrusted developers to directly write there. However, it might just make things more complicated, especially when all developers are trusted.

The choice of workflow does not necessarily affect the work in the local repository. Even if the workflow requires usage of several branches, it is possible to do everything in the master branch in the local repository and select a remote branch to push changes.

Centralized workflow could be used, when not many people are working on the project, and having a working bugless code in the master branch isn't very important.
Feature branch can be used when several developers are working on different features, and always having a working code in the master branch is important.
GitFlow is good in the same cases when feature branch is. Additionally, it could be useful when the product is being developed after the first release, and new versions keep getting released. Then a development branch could contain recently implemented features, and the master branch have only the new complete versions of the product.
Forking workflow is well-suited for situations, when not all the developers are trusted.

#### Committing one out of two.

If both files are already staged, B can be unstaged using
`git reset HEAD B`
then the following commands could be executed:
`git commit -m "added A"`
`git add B`
`git commit -m “added B”`
`git push`


#### Ignoring files.

There are two ways to ignore files: creating a local and/or a global .gitignore file.
A local .gitignore gitignore determines what files from one repository should be ignored. This information is shared with all other users who clone the repository. 
A global .gitignore file tells what files should be ignored in all the repositories on one computer. A changes in the global .gitignore do not affect other users.
Another way to ignore certain files for one user only (but not for all the repositories) is to create a file <git-directory>/info/exclude.


#### Merging vs rebasing. 

Merging does not change the branch that is getting merged. A merge commit contains all the changes that has been made in the branch after the branching (i.e. since the ancestor commit).
In case of rebasing, the commit history is rewritten and all the new commits from the master branch are added to the current branch. Then the current branch can be merged into the master branch. Thus, the history looks like one single line, since the current branch now has the same commits as the master branch.
Merging can make logs less readable. However, rebasing can be dangerous, when the “old” version of the branch is copied by another developer, that would cause conflicts. 

A rule of thumb: if more than one person is working on the branch, merging should be used.


#### Rewriting History. 

If the commit has not been pushed yet, it can easily be amended:
`git commit --amend -m "fixed commit message"`
The “wrong”  commit will be replaced with a new one.
If a commit has already been pushed, it could be amended and then force pushed (`git push origin --force`). 
For old commits, rebasing can be used, since it allows to rewrite the history. 
It is, however, not a good idea to edit commits that have already been pulled by someone else.


#### Stash your work.

`git stash` can be used to switch a branch without committing changes. This command saves the uncommited changes. The branch then can be switched.
To return to the stashed work, the command `git stash apply` can be used, it reapplies the most recent stash. The stash (if no longer needed) can then be removed by running `git stash drop`.

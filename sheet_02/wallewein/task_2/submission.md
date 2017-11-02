# Git cheat sheet

## Overview
This cheat sheet gives a short introduction to git usage and workflows.

## Initializing your own local repository
To start with your own local git repository, go to the preferred dir on your system and type:
```
$ git init 
```
This will create a folder named .git which is the version control database for your current project. Important is, that even if there are already files in your project folder, you have to add it to your version control manually, git does not recognize anything that is in this folder automatically.

To add files to your version control, which means to say git it should manage these files, type
```
$ git add [folder, file, ...]
```
To let git know that it should save your changes into a so called commit, type
```
$ git commit -m [message]
```
The message should be short and in best case in imperative form.
## Remote repositories & branching workflows
### Remote repositories
Remote repositories are often hosted on a server connected to the internet and are used to work together on projects all over the world. The following commands are important to work with remote repositories:

If you have already a remote repository, just clone it using
```
$ git clone [url]
```
You can view the linked remote repositories of your project using
```
$ git git remote -v
```
and add a remote repository with 
```
$ git remote add [shortname] [url]
```
To send your committed changes to a remote repository type
```
$ git push [remoteName] [branch]
```
### Branching
A branch is identified by a unique name and represents a series of changes of your project. Git has a HEAD pointer, which references the last commit of the current active branch. Branches are used to allow handling bug fixing, feature, release commits with different policies to make sure not to push errors into the master branch, which is the standard branch of each repository. In git only one branch can be active at a time.

To create a new branch from the current HEAD commit, type
```
$ git branch [name]
```
The following commits are placed in the newly added branch. To change to an existing branch, you can use 
```
$ git checkout [name]
```
To combine to branches to one, use the following command
```
$ git merge [targetBranch]
```
With this, git tries to merge the targetBranch into your current active branch. If there are are any conflicts, git marks in the files the lines where the conflicts are and show them with the corresponding branch. You have to manually merge the branches and create another commit with the corrected conflicts. Conflicts usually occur when the two branches have changes in the same file, especially in the same line of the file.

### Git workflows
#### Centralized Workflow
Only uses the remote master branch with the following workflow: 
- fetch changes
- resolve conflicts
- rebase own changes on top of master
- push into remote repository

There is only one remote repository, which has the latest version. The changes 

Pro's: 
- Easy to understand and use
- Latest version is always in the remote repository

Con's:
- Merge conflicts before pushing into remote master
- Single point of failure
- Potentially buggy master branch

#### Feature branch workflow
This approach is based on the idea, that every feature is developed in a dedicated branch and if the feature is ready, it will be merged into the master branch.
Workflow:
- Create or checkout the branch of the feature
- Make changes, commit them
- Push the changes to the remote branch of the feature
- Discuss and review the changes (pull request)
- If everything is fine, fetch changes from remote master and merge the feature branch into the master, resolve conflicts
- Push to remote master

Pro's:
- Easy parallel development of features
- Better code quality of master

Con's:
- Longer review process
- Feature branches could break other features

#### Git workflow
Idea: Extend feature branch workflow with roles and interactions of branches. The new branches are purpose driven, e.g. bugfix, feature specifc or development branch. 
Permanent branches:
- **master:** Latest stable release, only merged from release branch
- **development:** Current developed branch with features for next relase

Non-permanent branches:
- **feature:** new or modified behavior, will be merged into development branch
- **release:** Features or bugfixes for the next release
- **hotfix:** Important fixes, will be merged directly into master and development

Pro's:
- Very stable master
- Allows good management of features and bugfixing, good overview of development with the specific branches
- Stable releases

Con's:
- Very much effort to use this workflow

#### Forking workflow
Each developer has his own remote and local repository and there is one remote repository containing the main version of the project, which is except from the maintainers read only. Working with this workflow goes the following way:
- Fork from the main repository (which means create your own remote repository)
- Make changes in your local repository and push them into your remote repository
- Create a pull request, to notify the maintainers of the main repository that you have made changes that you want to apply on the repository
- The maintainer pulls into his local repository
- Discuss and review
- If everything is fine, he pushes the changes into the main remote repository

Pro's:
- Safe main repository allthough there are untrusted developers
- No write access for the developers necessary
- Trusted main code base

Con's:
- High effort to use this workflow, maintainers have much work to do pulling and reviewing source

#### When should I use one of these workflows
- **Centralized workflow:** If you have a small number of developers who can communicate well to minimize the effort of merge conflicts and who you can trust, that they don't push buggy code into the remote master
- **Feature branch workflow:** If you have features that can be developed parallel and in best case one developer for each feature
- **Git workflow:** Large project, many developers and many users of the software so that a buggy release is absolutely inacceptable
- **Forking workflow:** Large amount of developers you don't know and you don't trust

#### Which workflow will we use?
We decided to use the feature branch workflow, because it's a good compromise between code safety in master branch and the effort to handle branches and merges.

### Commiting one out of two
In general, with a git commit all files which are staged in index are committed. If you want to commit only a subset of files which are staged, you can pass them as arguments to git commit the following way:
```
$ git commit [file1] [file2] ...
```
This will apply only the passed files to the commit, ignoring the staged files in index. So in this case there is no need to remove files from index and readd them after commit.

### Ignoring files
Ignoring files in git means not to stage them using for example the git add command (except you use -f as param to git add). This is useful for binaries or libraries that should not be pushed into remote repository because they are to big. 

The default way to ignore files with git is adding a .gitignore file to the repository. In this file you can write patterns that match files or folders in your repository which should be ignored. The .gitignore file is recommended for files which should be ignored globally, which means for all developers.

If you want to ignore files only for your own local workflow, you can write the dedicated patterns into the $GIT_DIR/info/exclude file. The 

### Merging vs Rebasing
#### Rebasing
Another way to merge changes of one branch into another is the git rebase command. It applies the changes you made a second time to a target branch doing the following:
It goes back to the parent commit of both branches, calculates the differences of each commit in the current branch, saves and applies them on the current branch to set the base of the current branch to the last commit of the target branch. 

The following example shows the rebase operation. The current active branch is topic. Before rebasing
```
          A---B---C topic
         /
    D---E---F---G master
```
Command to rebase:
```
$ git rebase master 
$ git rebase master topic
```
After rebasing:
```
                  A'--B'--C' topic
                 /
    D---E---F---G master
```
#### Golden rule of rebasing
The golden rule of rebasing says: **Never use it on public branches**.
The reason for this is when you rebase your master into another branch, all other master branches are on a different commit and there has to be a merge commit to fix it. 

#### When to use rebase and merge
At first, both git merge and git rebase are used for the same operation, to apply changes from one branch into another. The point is, that git merge does not change the branches histories and makes only a new commit with the applied changes unlike git rebase, which rewrites the history of the current branch like you can see above. 

So use git merge if you have public branches and many developers to ensure not to rebase you own branches, push them and create different branches from all other developers branches. A drawback of merge is, that it can result into a quite polluted branch history.

If you want to have a clean branch history and you have the possibility to use rebase without breaking the golden rule, then it's recommended to use rebase.

### Rewriting history
To fix a prevoius commit in a very simple way you can use 
```
$ git commit --fixup [sha]
```
This will mark your commit as a fixup of a previous commit. After that call
```
$ git rebase --interactive --autosquash [branch]
```
so git will rebase the fixup commit on the right place into the branch history. If you don't want to make it automatically, interactive rebase offers you to do it manually.

### Stash your work
If you want to save your changes without committing them to checkout another branch you can call 
```
$ git stash save
```
to save your changes to a stash entry for your current branch. After that you can checkout other branches. To get back your stashed changes, type
```
$ git stash pop
```
after checking out your branch.
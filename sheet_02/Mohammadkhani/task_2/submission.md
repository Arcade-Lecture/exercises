# Initializing your own local repository
**Answer:** when we want to create a repository, we should use the git init command. this command is a one-time command you use during the initial setup of a new repository. you can also expect a new master branch.
```
$ git init
```
during your process, you can use "help command" to know more about the flexibility of git:
```
$ git help
```
now, in your file system, you can track history of any changes over time and compare different versions. 
If a project has already been set up in a repository, you can use this one-time command to obtain a development:
```
$ git clone <repo url>
```
# Remote repositories & branching workflows
**Answer:** How the branching feature is used is called branching workflow.

| workdflow        | benefit          | drawback  |
| ------------- |:-------------:| -----:|
| Centralized Workflow      | Easy to understand & to use  |  Merge conflicts before pushing into remote master |
| Feature Branch Workflow      | Parallel development of features  |  Longer reviewing process and risk of working on the out-dated code. |
| GitFlow Workflow | it gives you access to Git’s robust branching and merging model      |  it tends to slow down everything when you have a fast development/deployment flow  |
| Forking Workflow | Flexible workfow to securely collaborate with changing untrusted dev teams      |  For companies, employees are generally trusted. |

**The Centralized Workflow:** it uses a central repository to serve as the single point-of-entry for all changes to the project. 
the default development branch is called *master* and all changes are committed into this branch.  
This workflow doesn’t require any other branches besides *master*.  
Developers start by cloning the central repository. In their own local copies of the project, they edit files and commit changes. To publish changes to the official project, developers "push" their local *master* branch to the central repository.  
**The Feature Branch Workflow:** the core idea is that feature development should take place in a dedicated branch instead of the *master* branch.  
This encapsulation makes it easy for multiple developers to work on a particular feature without disturbing the main codebase. Encapsulating feature development also makes it possible to leverage pull requests, which are a way to initiate discussions around a branch.  
They give other developers the opportunity to sign off on a feature before it gets integrated into the official project.  
The Feature Branch Workflow assumes a central repository, and *master* represents the official project history. Instead of committing directly on their local master branch, developers create a new branch every time they start work on a new feature.  
Git makes no technical distinction between the master branch and feature branches, so developers can edit, stage, and commit changes to a feature branch.  
feature branches can (and should) be pushed to the central repository. This makes it possible to share a feature with other developers without touching any official code.  
**Gitflow Workflow:** it defines a strict branching model designed around the project release. This provides a robust framework for managing larger projects.  
Gitflow is ideally suited for projects that have a scheduled release cycle. This workflow doesn’t add any new concepts or commands beyond what’s required for the Feature Branch Workflow. Instead, it assigns very specific roles to different branches and defines how and when they should interact.  
Gitflow is really just an abstract idea of a Git workflow. This means it dictates what kind of branches to set up and how to merge them together.  Instead of a single master branch, this workflow uses two branches to record the history of the project.  
The master branch stores the official release history, and the develop branch serves as an integration branch for features. It's also convenient to tag all commits in the master branch with a version number.  
**Forking Workflow:** is fundamentally different than other popular Git workflows. Instead of using a single server-side repository to act as the “central” codebase, it gives every developer their own server-side repository.  
This means that each contributor has not one, but two Git repositories: a private local one and a public server-side one.  
The Forking Workflow typically follows a branching model based on the Gitflow Workflow. This means that complete feature branches will be purposed for merge into the original project maintainer's repository.  
The result is a distributed workflow that provides a flexible way for large, organic teams (including untrusted third-parties) to collaborate securely. This also makes it an ideal workflow for open source projects.  
the Forking Workflow begins with an official public repository stored on a server. But when a new developer wants to start working on the project, they do not directly clone the official repository. Instead, they fork the official repository to create a copy of it on the server.  

# Committing one out of two
**Answer:** for commiting A and B Seperately, these commands can be followed:
```
git rebase -i <oldsha1>
** mark the expected commit as `edit` (replace pick in front of the line), save and close
git reset HEAD^
git add ...
git commit -m "First part"
git add ...
git commit -m "Second part"
git rebase --continue
```

# Ignoring files
**Answer:** to avoid automatically generated files which generally produced your build system, we can create a file listing patterns to match them named `.gitignore`
for example:
```
$ cat .gitignore
*.[oa]
*~
```
which ignore any files ending in .o or .a — object and archive files that may be the product of building your code. The second line tells Git to ignore all files that end with a tilde (~), which is used by many text editors such as Emacs to mark temporary files.
there is an alternative way to avoid creating a global gitignore file and do it specifically. for Explicit repository excludes:
1. In Terminal, navigate to the location of your Git repository.
2. Using your favorite text editor, open the file .git/info/exclude.

# Merging vs rebasing
**Answer:** Both of these commands are designed to integrate changes from one branch into another branch—they just do it in very different ways.  
Merging is nice because it’s a non-destructive operation. The existing branches are not changed in any way. This avoids all of the potential pitfalls of rebasing.  
On the other hand, this also means that the feature branch will have an extraneous merge commit every time you need to incorporate upstream changes. If master is very active, this can pollute your feature branch’s history quite a bit. While it’s possible to mitigate this issue with advanced git log options, it can make it hard for other developers to understand the history of the project.  
The major benefit of rebasing is that you get a much cleaner project history. First, it eliminates the unnecessary merge commits required by git merge. Second, as you can see in the above diagram, rebasing also results in a perfectly linear project history—you can follow the tip of feature all the way to the beginning of the project without any forks.  
This makes it easier to navigate your project with commands like git log, git bisect, and gitk.
At the end, If you would prefer a clean, linear history free of unnecessary merge commits, you should reach for git rebase instead of git merge when integrating changes from another branch.  
On the other hand, if you want to preserve the complete history of your project and avoid the risk of re-writing public commits, you can stick with git merge. Either option is perfectly valid, but at least now you have the option of leveraging the benefits of git rebase.  

# Rewriting History
**Answer:** if you've just notice that you did a wrong thing on your last commit, you can change it with `git commit --amend`  
To modify older or multiple commits, you can use `git rebase` to combine a sequence of commits into a new base commit. In standard mode, git rebase allows you to literally rewrite history — automatically applying commits in your current working branch to the passed branch head. Since your new commits will be replacing the old, it's important to not use git rebase on commits that have been pushed public, or it will appear that your project history disappeared.

# Stash your work
Answer: for switching to another branch without committing your current changes, you need to stach your work. so you’ll stash the changes. To push a new stash onto your stack, run `git stash`:

```
$ git stash
Saved working directory and index state \
  "WIP on master: 049d078 added the index file"
HEAD is now at 049d078 added the index file
(To restore them type "git stash apply")
```
Your working directory is clean:
```
$ git status
# On branch master
nothing to commit, working directory clean
```
At this point, you can easily switch branches and do work elsewhere; your changes are stored on your stack. To see which stashes you’ve stored, you can use `git stash list`









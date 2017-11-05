## ARCADE Exercise 2 Task 2 Git usage
***
### Initializing own local repo
If the user never used git before he is advised to enter name and email for future references by using
```
$ git config --global user.name "Your Name Comes Here"
$ git config --global user.email you@yourdomain.example.com
```
 At first the user is required to initialize the basis of his future remote repository by creating it on his own machine. This can be done with
 ```
 $ git init
 ```
 after directing the terminal to the favoured directory. This will create a new folder named .git which saves all relevant data for git.

If the user does not wish to add already existing files to the git he is now done. Otherwise he would have to add those to git by 
```
$ git add <stuff>
```
with
```
. -> for all files
<name> -> for specific files or directories
```
to check for corret adding enter
```
$ git status
```
to view all added files. If everything is correct you can commit by
```
$ git commit -m '*Your commit message*'
```

### Remote repositories & branching workflows

| Name  | centralized  | feature branch  | gitFlow  | forking workflow  |
|---|---|---|---|---|
|  Remote Repo |  only one remote repository, all changes committed to master branch | seperate feature branch for development  | permanent master & development branch and nonpermanent patch or feature branches | multiple remote repos with one master repos |
| Merge Conflicts  | resolved locally  |  resolved remote, pull after pull request admission | resolved locally for nonpermanent | resolved by depending owner |
|Advantages | easy to use, only latest version | parallel development of features, pull requests, less buggy master| structured and traceable development order, even less buggy master and development | flexible workflow to securely collaborate with external devs, no write access must be handed out, excellent for open source development |
|Disadvantages | merge conflicts before pushing, single point of failure, can be buggy|longer intervall between pushes, less communication | can be oversized for smaller projects | in companies out of place because of lack of external devs |

When what to use -> pro/contra table

### Comitting one out of two

The user can remove file B out of his first commit and create a second one containing file B. This can be done by
```
$ git reset B
``` 
then push File A after that create new commit

```
$ git add A
$ git commit -m 'Second push'
```

### Ignoring Files
This can be achieved by modifying the `.gitignore` file and adding the desired files to the untracked filed for global scope.
Equally a file named `exclude` exists in the same directory which offers the same functionality but for a local scope only.

### Merging vs. Rebasing
```
$ git merge *primary* *secondary*
$ git rebase *primary* *secondary*
```
The main difference between merging and rebasing is that if rebasing is used all commits done to one branch will be done to the other and this one will be appended to the first branch. This can solve some issues that can occur when using merge. But can fill up the secondary branches history if the primary branch is quite active.

### Rewriting History
The latest commit message can be easily changed by using 
```
$ git commit --amend
```
this will give the user a text editor in which he can edit his message.
In case of a commit done before that the user has to rebase the repo to a certain point of the history by 
```
$ git rebase -i HEAD~*number of commits that came after desired one*
``` 
this will open a text editor in which the latest commit messages will be displayed, now the commit that needs to be changed needs to be changed from pick to edit. After saving and exiting the editor git will tell the user exactly what to do.
```
$ git commit --amend
$ git rebase --continue
```

### Stash your work
This can be achieved by using, before pulling the changes from remote repo, 
```
git stash
```
and can later be reapplied by
```
git stash pop
```
or if the users wants to keep his stash
```
git stash apply
```

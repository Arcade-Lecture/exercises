### Initializing your own local repository

first you need to install git on your machine by typing `apt-get install git-all`.
then create a Directory that suppose to include the Project Files and go to this Directory
From the Repository Directory you should type `git init` then a folder called `.git` will be created and this Directory will include all the git Repository informations like changes , comments, history ..etc

after you add files to project Directory you should add them to git by using this command `git add <file path>`

### Remote repositories & branching workflows


### Committing one out of two
we can commit each file once by typing:

```
$ git commit A
$ git commit B
```

### Ignoring files

we can create a .gitignore file by typing: `touch .gitignore`
and add the files you want to ignore to it 

hint: `.gitignore`  ignores just files that weren't tracked before so you need first to unstage the files by using `git reset name_of_file`


### Merging vs rebasing

Merge takes all the changes in one branch and merges them into another branch in one commit.

Rebase says I want the point at which I branched to move to a new starting point (rewrite commit history)

Rebase will make the commit history line much cleaner but the problem is that it loses the context provided by a merge commit


### Rewriting History

before the push: `git commit --amend -m "fixed commit message"`
after push: `git rebase -i HEAD~<commitNumber>` and then retype `git commit --amend -m "fixed commit message"` and finally continue the Rebase `git rebase --continue`


### stash your work

You can save the uncomitting changes by using a command `git stash` and then you can switch to another branch
then when you back to bransh and you want to continiue then you have to run `git stash apply`, when the stash is no longer needed you can clear it by using `git stash drop` 





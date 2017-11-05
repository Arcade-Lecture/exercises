### Initializing your own local repository

If you want to create a local repository, you have to do `git init` to initalize a local repository. It will create a `.git` folder, which contains the necessary files to provide a local repository.

### Remote repositories & branching workflows

If you want to clone a remote repository, you have to use `git clone <url>`. This will create a new folder in the current directory with the repository name as folder name.

You can use the linked remote repositories with `git remote -v`.

If you want to add an upstream repository to an existing local repository with `git remote add <shortname> <url>`.

If you want ot send your changes to the an upstream repository, you may want to use `git push <shortname> <branch>`

| | Centralized | Feature-Branches | GitFlow | Forking |
|---|------------------|---------|---------|--|
| Remote Repositories | 1 | 1 | 1 | u |
| Remote Branches | | | | |
| Lifetime of Branches | | | | |
| Responsible for Merges | | | | |
| Benefit | | | | |
| Drawback | | | | |


### Commiting one out of two

You can commit one out of two files, if you use `git commit <file1> <file2>` with parameters. If you use it with parameters, `git commit` will ingore your staged changes and will only commit the appended files. You can also use -m with those file parameter.


### Ignoring files

If you use build systems and IDEs, you may have files, which should not be checked in. 

If you want to ignore a file or directory for the whole repository, you can use the `.gitignore` file. 

If you only want to exclude files for your local workflow, you may want to use the exclude file, which is located at `$GIT_DIR/info/exclude`. You can use this file similar to any `.gitignore` file.

### Merging vs rebasing

If you merge changes, you will create a commit, which merges both changes to one branch. Any branch, which get merged by another branch, won't contain the history of the other branch, only the merge commit.

```
git merge <branch>
```

If you rebase your changes to another branch, the branch will contain the whole history of commits and changes after the rebase.

```
git rebase <branch>
```

Both commands will merge your currently checked out branch to the branch in the parameters.

### Rewriting History

If you want to rewrite your last commit, you can use `git commit --amend`. If you want to change older commits, you may have to use another command, which is called `git rebase -i HEAD~<commitNumber>`. Your preferenced editor will open with an file. After saving your file, you have to append this to your last commit and rebase the branch with `git commit --amend` and `git rebase --continue`.

### Stash your work

You can save your work with `git stash`. Afterwards you have a clean folder, so you can switch to other branches, etc. Afterwards you can get your changes back with `git stash pop`.


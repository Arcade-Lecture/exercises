# 1, Initializing your own local repository
```
You'll first cd to the root project folder and then execute the git init command.

so type that in your Console  :
$cd /path/to/your/existing/code

then

$git init

now you have your own git repository

With follow step you can add some file oder folder with a messenger on your repository

$git add<folder or file > add folder or text on your repository
$git commit -m"Your messenger"  
$git push origin <Your repository_name>

```
# 2, Remote repositories & branching workflows
```
Remote

$git clone <repository_url>

git clone is primarily used to point to an existing repo and make a clone or copy of that repo at in a new directory, at another location.

$cd repository_name

and now you can work on that repository

now if you type
$git remote
you will see
$origin

$git remote -v

you will see something like this
<username>  git://github.com/yyyxxxyyc/xxxxcx.git

that means all the people work on your repository and you can download them code

if you want add a Remote Repository, just type
$git remote add <shortname_of_project> <repository_url>

now type
§git fetch


Branching

With

$git checkout -b <Your_branch_name>

can you create a new branch and in the same time you switched to your new branch

Just by typing

$git branch

you can see in which branch you are

In Git, branches are a part of your everyday development process. When you want to add a new
feature or fix a bug—no matter how big or how small—you spawn a new branch to encapsulate
your changes. This makes sure that unstable code is never committed to the main code base,
and it gives you the chance to clean up your feature’s history before merging it into the
main branch.


```
# 3, Committing one out of two
```
with
$git reset --soft "B"
$git commit ....

```
# 4, Ignoring files
```
 A gitignore file specifies intentionally untracked files that Git should ignore, so in this
 case i will create a gitignore file and write name of files i will not commit in our repository in gitignore file , like this

 $ git status
   [...]
   # Untracked files:
   [...]
   #       Documentation/foo.html
   #       Documentation/gitignore.html
   #       file.o
   #       lib.a
   #       src/internal.o
   [...]
   $ cat .git/info/exclude
   # ignore objects and archives, anywhere in the tree.
   *.[oa]
   $ cat Documentation/.gitignore
   # ignore generated html files,
   *.html
   # except foo.html which is maintained by hand
   !foo.html
   $ git status
   [...]
   # Untracked files:
   [...]
   #       Documentation/foo.html
   [...]
   @https://git-scm.com/docs/gitignore

```
# 5, Merging vs rebasing
```
$git merg <branch you want to merge > <your new branch>

after typing that you had merge two branch in one , so that will maybe arise a merge conflict
but that will very easy to fix , just remote line of code from another branch


Rebase as an alternative to merging

$git checkout <your branch>
$git rebase master

```
# 6, Rewritting History
```
If you only want to modify your last commit message, it’s very simple:
$ git commit --amend

Changing Multiple Commit Messages
$ git rebase -i HEAD~3

```
# 7, Stash your work
```
Use $git stash when you want to record the current state of the working directory and the index, but want to go back to a clean working directory. use $git stash pop you will get your changes back


```

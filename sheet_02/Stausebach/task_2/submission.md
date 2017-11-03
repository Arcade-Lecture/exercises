Initializing your own local repository
    
    Create a folder for your local repository with "mkdir MyProject"
    "cd MyProject"
    Initialize the repository using "git init"
    Add a new file to the repository"touch README"
    "git add README"
    Commit the new file to your git repository "git commit -m ..."
    The next step is to specify the remote host, which in our case is the localhost
    "git remote add origin git@localhost:MyProject"
    Now push the file using "git push origin master"

    



    
Remote repositories & branching workflows
        
    Remote repository
    With "git remote add origin <url of repository>" you can make a copy of an existing git repository and copy it into a local directory.
     
    Branching
    The command "git branch" will show all branches available for your projects.
    If you want to create a new branch use "git checkout -b <branch_name>".
    e.g. branches can be used to fix bugs. Doing this on a new branch instead on the main code base, makes sure that unstable code is never commited to the main code base.

    


 
    
Comitting one out of two

    "git status"
    git add [some files]
    git commit [some files]

    


 
    
Ignoring files
    
    If you create a file in your repository named .gitignore, Git uses it to determine which files and directories to ignore, before you make a commit.
    .gitignore file should be committed into your repository, in order to share the ignore rules with any other users that clone the repository
    



 
    
Merging vs rebasing
    
    "git merge <branch a> <branch b>"
    "git rebase master"
    Merging is nice because it’s a non-destructive operation
    The existing branches are not changed in any way
    The major benefit of rebasing is that you get a much cleaner project history
    First, it eliminates the unnecessary merge commits required by "git merge"
    Second,rebasing also results in a perfectly linear project history
    



 
    
Rewriting History

    Modify last commit message
    "git commit --amend"
    Modify multiple messages
    git rebase -i HEAD~3
            
    



 
    
Stash your work

    With "git stash" you can save the current state of your repository and go back to a clean state.
    Use "git stash pop" to go back to the state with the changed files.



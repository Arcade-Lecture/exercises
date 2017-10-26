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
        
        
        
        
        
        

    


 
    
        Comitting one out of two
        "git status"
        git add [some files]
        git commit [some files]

    


 
    
        Ignoring files
        If you create a file in your repository named .gitignore, Git uses it to determine which files and directories to ignore, before you make a commit.
        .gitignore file should be committed into your repository, in order to share the ignore rules with any other users that clone the repository
    



 
    
        Merging vs rebasing
        Merging is nice because it’s a non-destructive operation
        The existing branches are not changed in any way
        The major benefit of rebasing is that you get a much cleaner project history
        First, it eliminates the unnecessary merge commits required by "git merge"
        Second,rebasing also results in a perfectly linear project history
    



 
    
        Rewriting History
        Modify last commit message
        "git commit --amend"
        Modify multiple messages
        git rebase -i
    



 
    
        Stash your work
        git stash
    



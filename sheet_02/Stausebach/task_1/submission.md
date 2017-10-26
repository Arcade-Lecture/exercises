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
    



    
        <h1>Remote repositories & branching workflows</h1>
        
        
        
        
        
        

    


 
    
        <h1>Comitting one out of two</h1>
        "git status"
        git add [some files]
        git commit [some files]

    


 
    
        <h1>Ignoring files</h1>
        If you create a file in your repository named .gitignore, Git uses it to determine which files and directories to ignore, before you make a commit.
        .gitignore file should be committed into your repository, in order to share the ignore rules with any other users that clone the repository
    



 
    
        <h1>Merging vs rebasing</h1>
        Merging is nice because it’s a non-destructive operation
        The existing branches are not changed in any way
        The major benefit of rebasing is that you get a much cleaner project history
        First, it eliminates the unnecessary merge commits required by "git merge"
        Second,rebasing also results in a perfectly linear project history
    



 
    
        <h1>Rewriting History</h1>
        Modify last commit message
        "git commit --amend"
        Modify multiple messages
        git rebase -i
    



 
    
        <h1>Stash your work</h1>
        git stash
    



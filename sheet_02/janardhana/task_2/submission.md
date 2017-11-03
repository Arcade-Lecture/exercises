
# TASK 2

1. **To initialise local repository follow two steps**
    1. Create a local directory 
    2. Open bash, enter created directory and run `git init`
    *if there are any files to add to the repository*
    3. Use `git add filename` to add particular files or use `git add .` to add all files 
    4. Finally run `git commit -m "commit message"` to commit files
  
2. **Remote repositories and branching workflows.**

| Workflow      | #remote repositories| #remote branches    | branch lifetime |Merge responsibility | Benefit            | Drawback              |
|:-------------:|:-------------------:|:-------------------:|:---------------:|:---------------------:|:-----------------: |:---------------------:|
| Centralized   | one                 | one                 | permenant       | users using the repo| Just one branch to maintain |conflicts may occur if lot of upstream changes|
| Feature branch| one                 | one or more         | till the branch is merged| users of particular branch |allows user to work independently | requires too many merge or rebasing to maintain updated code base   |
| Git Flow      | one                 | two to many         | temporary/permanent| user responsible for changes            |suitable for large scale projects |complex            | 
| Forking       | one or more         | one to many         | temporary/permanent| reposity maintainer          |suitable for opensource projects |only suitable for long living projects accepting external contrubutions|
 
Rule of thumb for using workflows: 

Centralized   : short span projects and people who and transitioning from SVN
Feature branch: Projects with enhancements and decent team size
Git flow      : Long living projects with many releases.
Forking       : For opensource projects

3. **To commit one out of two files**

    If you've made changes to two files A and B and want to commit each file with different commit message follow the below procedure:

   * *Add the files to staging*

        `git add A`


   *  *Check to see what you are committing*

        `git status`

      Changes to be committed:
          modified:   A

      Changes not staged for commit:
          modified:   B 
    
    * *Commit the files with a commit message*
    
      `git commit -m "Commiting A out of A B"`

      *Repeat the same procedure for B*   
    
 4. **Ignoring files**
 
    To ignore IDE-specific files (local ignorance rather than global ignorance) in shared reporisotory
    
        1. Open bash, navigate to location of your git repository
        
        2. open git/info/exclude file and add files to be ignored
       
  5. **Merging v/s Rebasing**
      
      Both merging and rebasing outputs same result, only difference is the procedure followed to approach.
      Consider, we have Master and feature branch. If Master has some important commits that is to be moved to feature then this can be
      done by merging or rebasing
      
      **Merging**
      
       * Merging is non-destructive operation the existing branches are not changed in anyway 
       * Causes an extraneous merge commit everytime we include upstream changes
       * Merging can be used when you want only particular changes to be included in feature branch
       
       **Rebasing**

       * This moves entire feature branch to start from the tip of master branch irrespective of where branching was done
       * Benifit of rebasing is it allows for clear linear project history 
       * Rebasing can be used when you want tip of feature all the way to master without any forks
  
  6. **Rewriting history**
  
      * In-orderto change the previous commit's message("fox") without altering it's snapshot use `git commit --amend -m "fix"`
      
        *--amend is the flag used to fix this minor mistakes*
      
      * To make changes to the older commits, use `git rebase -i`, git will pop up an editor to handle those commits, notice this command: #  r, reword. Then continue with `$git commit --amend -m "new updated message"`
      
     
  7. **Stash your work**
  
      * when you want to switch from one branch to the other, but you want to save the changes of the current branch that you are working on, use `git stash` to stash the changes.
        Changes can  be stashed when you don't want to commit right away but sometime later
      
      * The stashed changes can be applied by `git stash apply`

      
  
  
  
  
  
  

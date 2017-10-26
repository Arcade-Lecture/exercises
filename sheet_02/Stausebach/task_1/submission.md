<table>
    <tr>
        <td>Initializing your own local repository</td>
	<td>Create a folder for your local repository with "mkdir MyProject"</td>
	<td>"cd MyProject"</td>
        <td>Initialize the repository using "git init"</td>
        <td>Add a new file to the repository"touch README"</td>
        <td>"git add README"</td>
        <td>Commit the new file to your git repository "git commit -m ..."</td>
        <td>The next step is to specify the remote host, which in our case is the localhost</td>
	<td>"git remote add origin git@localhost:MyProject"</td>
        <td>Now push the file using "git push origin master"</td>
    </tr>
</table>

<table>
    <tr>
        <td>Remote repositories & branching workflows</td>
        <td></td>
        <td></td>
        <td></td>
        <td></td>
        <td></td>
        <td></td>

    </tr>
</table>

<table> 
    <tr>
        <td>Comitting one out of two</td>
        <td>"git status"</td>
        <td>git add [some files]</td>
        <td>git commit [some files]</td>

    </tr>
</table>

<table> 
    <tr>
        <td>Ignoring files</td>
        <td>If you create a file in your repository named .gitignore, Git uses it to determine which files and directories to ignore, before you make a commit.</td>
        <td>.gitignore file should be committed into your repository, in order to share the ignore rules with any other users that clone the repository</td>
    </tr>
</table>


<table> 
    <tr>
        <td>Merging vs rebasing</td>
        <td>Merging is nice because it’s a non-destructive operation</td>
        <td>The existing branches are not changed in any way</td>
        <td>The major benefit of rebasing is that you get a much cleaner project history</td>
        <td>First, it eliminates the unnecessary merge commits required by "git merge"</td>
        <td>Second,rebasing also results in a perfectly linear project history</td>
    </tr>
</table>


<table> 
    <tr>
        <td>Rewriting History</td>
        <td>Modify last commit message</td>
        <td>"git commit --amend"</td>
        <td>Modify multiple messages</td>
        <td>git rebase -i</td>
    </tr>
</table>


<table> 
    <tr>
        <td>Stash your work</td>
        <td>git stash</td>
    </tr>
</table>


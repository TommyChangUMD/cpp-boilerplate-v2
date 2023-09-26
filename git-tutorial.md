# Basic commands
```bash
git add <file>
git rm <file>
git push
git pull
git log
git status
git checkout <branch_name>
git branch
git fetch
git diff
git stash
git commit
git reset
git help
```


# Clone any Git repository and add it to your GitHub


## 1.) clone a git repo
It could be any repo.  Let's use cpp-boilerplate-v2 as an example.
```bash
git clone https://github.com/TommyChangUMD/cpp-boilerplate-v2
cd cpp-boilerplate-v2
```

## 2.) list all branches
```bash
git branch -va
```

Assume the output shows a branch called "main".

## 3.) checkout all branches you want to clone
```bash
git checkout main
git checkout <branch_name>
...
```

## 4.) list all remotes
```bash
git remote show
```

## 5.) remove the remote origin
```bash
git remote remove origin
```

## 6.) list all remote again to verify
```bash
git remote show
```

## 7.) Now, go to your GitHub and create an empty repo.  Give it any name you want.

1. Click: Profile Icon->"Your repositories"->"New" button

2. Assign a "Repository Name" (could be any name you want)

3. Click the "Create repository" button

4. Get the repo's ssh name.  For example:

```
git@github.com:TommyChangUMD/delem.git
```

## 8.) Assign the cloned repo a new remote origin
```bash
git remote add origin <the_repo_name_from_previous_step>
```

## 9.) List remote again to verify
```bash
git remote show
git remote show origin
```

## 10.) Add all branches back
```bash
git push --set-upstream origin main
git push --set-upstream origin <branch_name>
...
```

## 11.) List all branches to verify
```bash
git branch -va
```

You should now see the remote branches in the list.

## 12.) Set default HEAD branch (usually "main" )
```bash
git remote show origin
git remote set-head origin main
```

## 13.) Verify the new repo in GitHub

You should now get an identical repo in which you can modify.  How is
this different from forking a repo?  A forked repo can not be forked
in general.

# Delete a repository on GitHub
1. Click: Profile Icon->"Your repositories"
2. Click the repo you want to delete
3. Click "Settings" (next to the gear icon)
4. Scroll all the way down to the "Danger Zone" section
5. Click "Delete this repository" 

# Create a new empty repo on GitHub
1. Click: Profile Icon->"Your repositories"->"New" button
2. Assign a "Repository Name" (could be any name you want)
3. Click the "Create repository" button

# Fork a Git repository on GitHub
1. Go to repo GitHub you want to fork and click "Fork"
2. Assign a "Repository Name" for the forked repo
3. Click the "Fork" button

# Create a Pull/Merge Request 
## using GitHub
1. Commit some changes to the forked repo (in a separate branch)
2. Click "Pull Request"
3. Review your changes
4. Click "Create pull request"
5. Write the request message.
6. Click the "Create Pull Request" button
## using command-line
Just create a branch.  And then email your repo and branch name to the original author.

# Accept a Pull/Merge Request 
## using GitHub
0. The original repo author goes to his/her GitHub
1. A number "1" shows up next to "Pull Requests", click on it.
2. Review the request message and the proposed changes.
3. Write comment if needed.
5. If everything looks good, click the "Merge pull Request" option (instead of the "Squash and Merge" option)
6. Click "Confirm merge"
7. By default the changes will be merged into the main branch
## using command-line
1. Get the forked_repo and branch_name from the person who sent the pull request.
2. from the main branch, do
```
git pull <forked_repo> <branch_name>
```

# Keep your fork up to date
## using GitHub
Click "sync fork" 
## using command-line
1. setup upstream remote repo
```bash
# Add 'upstream' repo to list of remotes
# git remote add upstream <ori_repo>, for example
git remote add upstream git@github.com:TommyChangUMD/cpp-boilerplate-v2.git

# verify step
git remote show 
git remote show upstream
```
2. merge with the latest upstream's main branch
```bash
git checkout main 
git pull upstream main
git commit -m "sync with upstream"
git push
```


# Help! I messed up my repo/branch
As long as you have *not* issued `git push` nothing has been sent to the git server.  Even if you did a bunch of `git rebase`.

If the repo is not tracked, just delete the directory.

If the repo is tracked, get the tracking branch info:
```bash
git status
# Your branch is ahead of 'origin/my_branch_2' by 1 commit.
```
Then issue `git reset --hard <full_branch_name>`
```bash
git reset --hard origin/my_branch_2
```
Warning: Very dangerous.

# I want to discard all my changes
```bash
git checkout .
```
Warning: Very dangerous.


# Rebase topics
Pretty much lets you modify/redo/edit any git commit that has been
pushed already.  --- Alter the commit history!
## Merging
Main has Diverged:
```
... o ---- o ---- A ---- B  origin/main (upstream work)
                   \
                    C  main(your work)
```

Merge from upstream will create M, which has 2 parents now -- no longer lineaer history:
```
... o ---- o ---- A ---- B  origin/main (upstream work)
                   \      \
                    C ---- M  main (your work)
```

Rebase will moidfy C to C' -- still linear history:

```
... o ---- o ---- A ---- B  origin/main (upstream work)
                          \
                           C'  main (your work)
```

Typical Branch:
```
A - B - C - D  - E - F - G <-master
                  \
                   E1 - E2 <- branch-b
```
Merge branch to main will lose branch history after creating H.
```
A - B - C - D  - E - F - G - H <-master
                  \       /
                   E1 - E2 <- branch-b                   
```

Rebase will moidfy E1 and E2 to E1' and E2' -- still linear history:

```
A - B - C - D  - E - F - G <-master
                  \       \
                   E1 - E2 \ 
                            E1' - E2' <- branch-b
```

To use the rebase method:
```bash
git pull --rebase
```

ref https://stackoverflow.com/questions/2452226/master-branch-and-origin-master-have-diverged-how-to-undiverge-branches

ref https://stackoverflow.com/questions/28407020/keep-commits-history-after-a-git-merge

## Redo commit message that has been pushed already
1. get the commit sha1 IDs
```bash
git log
```
2. start the rebase process
```bash
git rebase -i <sha1_id_parent_of_commit> 
```
3. The default editor will popup, choose the *reword* command
4. Edit the commit message
5. push the change:
```bash
git push --force
```

## Redo a particular old commit that has been pushed already
1. get the commit sha1 IDs
```bash
git log --oneline
```
2. start the rebase process
```bash
git rebase -i <sha1_id_of_parent_commit> 
```
3. The default editor will popup, choose the *edit* command
4. Add, remove, edit files, etc. 
5. Commit the changes
5. finish the rebase process:
```
git rebase --continue
```
5. Finally push the change:
```bash
git push --force
```
## Squash a series of commits that have been pushed already into one
1. get the commit sha1 IDs
```bash
git log --oneline
```
2. start the rebase process
```bash
git rebase -i <sha1_id_of_parent_commit> 
```
3. The default editor will popup, mark the first / top commit *edit* and the result *squash*.
4. Commit the change
5. finish the rebase process:
```
git rebase --continue
```
6. Finally push the change:
```bash
git push --force
```

## Change the timestamps of commits that has been pushed already
Change both the `author date` and `commit date` for all commits after a particualr commit.
```bash
T=2022-08-12T13:57:58-04:00
git rebase <sha1_id_of_parent_commit> --exec "GIT_COMMITTER_DATE='$T' git commit --amend --no-edit --date '$T'"
```
ref: https://stackoverflow.com/questions/454734/how-can-one-change-the-timestamp-of-an-old-commit-in-git

# MISC.
## Bash prompt with git branch name
To get a nice bash shell prompt with git branch info, do:

```bash
export PS1="\n\t \[\033[32m\]\w\[\033[33m\]\$(GIT_PS1_SHOWUNTRACKEDFILES=1 GIT_PS1_SHOWDIRTYSTATE=1 __git_ps1)\[\033[00m\] $ "
```
## Show both commit and author timestamps
```bash
git log --pretty=fuller
```

## See the list modifiled files in the commit log
```bash
git log --name-only
```

## List commit logs, one per line
```bash
git log --oneline
```

## Remove all unknown / untracked files
```bash
git clean -df
```

## Graphical program
```bash
gitk
# to show all branches
gitk --all
```

## Get the last push timestamp from GitHub
Replace "https://github.com/" with "https://api.github.com/repos/"
example:
```bash
# for repo at https://github.com/TommyChangUMD/cpp-boilerplate-v2, do
curl https://api.github.com/repos/TommyChangUMD/cpp-boilerplate-v2 
curl https://api.github.com/repos/TommyChangUMD/cpp-boilerplate-v2 | grep pushed_at
```

ref: https://code.mendhak.com/simple-bash-prompt-for-developers-ps1-git/

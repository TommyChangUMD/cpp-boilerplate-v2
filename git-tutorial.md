# Git commands you should know
```bash
git add <file>
git rm <file>
git push
git pull
git log
git status
git checkout <branch_name>
git checkout -b <new_branch_name>
git branch -D <old_branch_name>
git branch -M <new_branch_name>
git fetch
git remote
git diff
git stash
git commit
git reset
git tag
git rebase
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
git branch -a
```

## 3.) checkout all branches you want to clone
```bash
git checkout main
git checkout <branch_name>
...
```

## 4.) list all remote repos
```bash
git remote show
```

## 5.) remove the remote repo called "origin"
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
git@github.com:TommyChangUMD/delme.git
```

## 8.) Assign the cloned repo a new remote called "origin"
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
git push -u origin main
git push -u origin <branch_name>
...
```

Note: You may be prompted with username and password every time 'git push' is invoked.

To avoid such inconvenience, you can configure your GitHub account to
use SSH keys. There are many tutorials available on the web. Here's
one such tutorial:

https://www.inmotionhosting.com/support/server/ssh/how-to-add-ssh-keys-to-your-github-account


## 11.) List all branches to verify
```
git branch -a
```

You should now see both the *local and remote* branches in the list.  For example:
```bash
main
remotes/origin/main
...
```


## 12.) Set default HEAD branch (usually "main" )
```bash
git remote show origin
git remote set-head origin main
```


## 13.) Verify the new repo in GitHub

You should now get an identical repo, which you can modify.  How is
this different from forking a repo?  

A forked repo can not be forked again.

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
1. Commit some changes to the forked repo (in a separate new branch)
2. Click "Pull Request"
3. Review your changes
4. Click "Create pull request"
5. Write the request message.
6. Click the "Create Pull Request" button
## using command-line
Just create a new branch to do you work.  When done, email your repo and branch names to the original author.

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
1. Get the *repo* and *branch* names from the person who sent the pull request.
2. from the main branch, do
```
git pull <repo_name> <branch_name>
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

# Branch topics

## Delete a branch
```bash
# switch to the local working branch
git checkout <old_branch_name>

# delete the local branch
git branch -D <old_branch_name>

# delte the remote branch
git push origin -d <new_branch_name>
```

## Rename a branch
```bash
# switch to the local working branch
git checkout <old_branch_name>

# rename the local branch name
git branch -M <new_branch_name>

# change the remote branch name
git push origin -u <new_branch_name>

# delete the old remote branch name
git push origin -d <new_branch_name>
```

# Local repo topics
## Discard all my local changes
```bash
git checkout .
```
Warning: Will lose all changes you made to the local branch.

## Stash away all my local changes temporarily 
```bash
# stash away the changes
git stash

# verify that a stash has been created
git stash list

# bring back the changes from the last stash
git stash pop
```



## keep the local repo up-to-date
```bash
git fetch
```
Or 
```bash
git remote update
```

Very important!  You local repo is not going get updated from the git
server automatically on its own.  Once updated, you can see new
branches, commits, etc. if any.



# Rebase topics
Pretty much lets you modify/redo/edit any git commit that has been
pushed already.  --- It can alter the commit history!
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


To use the rebase method:
```bash
git pull --rebase
```

ref https://stackoverflow.com/questions/2452226/master-branch-and-origin-master-have-diverged-how-to-undiverge-branches

ref https://stackoverflow.com/questions/28407020/keep-commits-history-after-a-git-merge

## Modify commit message that has been pushed already
1. get the commit sha1 IDs
```bash
git log
```
2. start the rebase process
```bash
git rebase -i <sha1_id>~1
```
Here `~1` means the immediate predecsor (i.e, the parent of the commit).

3. The default editor will popup, choose the *reword* command
4. Edit the commit message
5. push the change:
```bash
git push --force
```
Here `--force` is needed to rewrite the commit history of the remote branch.


## Modify a particular old commit that has been pushed already
1. get the commit sha1 IDs
```bash
git log --oneline
```
2. start the rebase process
```bash
git rebase -i <sha1_id>~1
```
3. The default editor will popup, choose the *edit* command
4. Add, remove, edit files, etc. 
5. Commit the changes with the `--amend` option
```bash
git commit --amend
```
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
4. Commit the changes with the `--amend` option
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
git rebase <sha1_id>~1 --exec "GIT_COMMITTER_DATE='$T' git commit --amend --no-edit --date '$T'"
```
ref: https://stackoverflow.com/questions/454734/how-can-one-change-the-timestamp-of-an-old-commit-in-git

# Help! I seriously messed up my repo/branch
It's easy to mess up your local repo with `git rebase`.  However, as long as you have *not* issued `git push` nothing has been sent to the git server.

First, get the tracking info (i.e, the corresponding remote branch name):
```bash
git status
# Your branch is ahead of 'origin/my_branch_2' by 1 commit.
```
Then issue `git reset --hard <remote_branch_name>`
```bash
git reset --hard origin/my_branch_2
```
Warning: Will lose all changes you made to the local branch.

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

## Show the list of modifiled files in the commit log
```bash
git log --name-only
```

## Show each commit entry in one line
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

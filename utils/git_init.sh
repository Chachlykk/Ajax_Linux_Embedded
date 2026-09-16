#!/bin/bash

source .git_myconfig
git config --local user.name "$USER_NAME"
git config --local user.email "$USER_EMAIL"
git config --local init.defaultBranch "$USER_BRANCH"
if git remote get-url origin >/dev/null 2>&1; then
	git remote set-url origin "$USER_REPOSITORY"
else
	git remote add origin "$USER_REPOSITORY"
fi

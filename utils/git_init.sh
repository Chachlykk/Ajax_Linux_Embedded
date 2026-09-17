#!/bin/bash

if [[ ! -f ".git_myconfig" ]]; then
	echo "Configuration file is not found"
	read -r -p "Create it> [y/N]" answer
	if [[ "$answer" == "y" ]]; then
		read -r -p "Enter user name:" USER_NAME
		read -r -p "Enter user email:" USER_EMAIL
		read -r -p "Enter default branch:" USER_BRANCH
		read -r -p "Enter remote repository:" USER_REPOSITORY
		cat > .git_myconfig <<EOF
USER_NAME="$USER_NAME"
USER_EMAIL="$USER_EMAIL"
USER_BRANCH="$USER_BRANCH"
USER_REPOSITORY="$USER_REPOSITORY"
EOF
	fi
else
	source .git_myconfig
fi


if git -C . rev-parse --is-inside-work-tree >/dev/null 2>&1; then
	echo -e "Git repository exists.\nExiting"
	exit 1
fi

git config --local user.name "$USER_NAME"
git config --local user.email "$USER_EMAIL"
git config --local init.defaultBranch "$USER_BRANCH"
git remote add origin "$USER_REPOSITORY"


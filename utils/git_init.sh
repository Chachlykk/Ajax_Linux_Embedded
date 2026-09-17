#!/bin/bash

create_config(){
	read -r -p "Enter user name:" USER_NAME
	read -r -p "Enter user email:" USER_EMAIL
	read -r -p "Enter default branch:" USER_BRANCH
	read -r -p "Enter remote repository:" USER_REPOSITORY
	cat > "$1/.git_myconfig" <<EOF
USER_NAME="$USER_NAME"
USER_EMAIL="$USER_EMAIL"
USER_BRANCH="$USER_BRANCH"
USER_REPOSITORY="$USER_REPOSITORY"
EOF
}

if [[ -n $1 ]]; then

	if git -C $1 rev-parse --is-inside-work-tree >/dev/null 2>&1; then
		echo -e "Git repository exists.\nExiting"
		exit 1
	fi

	if [[ ! -e $1 ]];then
		mkdir -p $1
	fi

	if [[ ! -f "$1/.git_myconfig" ]]; then
		echo "Configuration file is not found"
		read -r -p "Create it> [y/N]" answer
		if [[ "$answer" == "y" ]]; then
			create_config $1
		else
			echo -e "No config file\bExiting"
			exit 2
		fi
	else
		source "$1/.git_myconfig"
	fi

	if [[ -x "$USER_NAME" || -z "$USER_EMAIL" || -z "$USER_BRANCH" ]]; then
		echo "Not enough settings, check .git_myconfig file"
		exit 3
	fi

	git -C "$1" init
	git -C $1 config --local user.name "$USER_NAME"
	git -C $1 config --local user.email "$USER_EMAIL"
	git -C $1 config --local init.defaultBranch "$USER_BRANCH"
	git -C $1 remote add origin "$USER_REPOSITORY"
else
	echo -e "Usage:\n$0 <directory>\n$0 <directory> <remote_utl>"
fi

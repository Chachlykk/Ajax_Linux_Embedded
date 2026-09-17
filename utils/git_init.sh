#!/bin/bash

create_config(){
	read -r -p "Enter user name:" USER_NAME
	read -r -p "Enter user email:" USER_EMAIL
	read -r -p "Enter default branch:" USER_BRANCH
	cat > ".git_myconfig" <<EOF
USER_NAME="$USER_NAME"
USER_EMAIL="$USER_EMAIL"
USER_BRANCH="$USER_BRANCH"
EOF
}

check_dir(){
	if git -C $1 rev-parse --is-inside-work-tree >/dev/null 2>&1; then
		echo "Git repository exists."
		if [[ -n $2 ]]; then
			if git -C $1 remote get-url origin >/dev/null 2>&1; then
				echo "Remote repository changed"
				git -C $1 remote set-url origin $2
			else
				echo "Remote repository added"
				git -C $1 remote add origin $2
			fi
		fi
		echo "Exiting"
		exit 0
	elif [[ -n "$(find "$1" -mindepth 1 -maxdepth 1 -print -quit)" ]]; then
		echo -e "Dir is not empty.\nExiting"
		exit 1
	fi

	if [[ ! -e $1 ]];then
		mkdir -p $1	
	fi
}
if [[ -n $3 ]]; then
	echo -e "Too many parameters\nExititng"
	exit 4
fi

if [[ -n $1 ]]; then
	check_dir $1 $2

	if [[ ! -f .git_myconfig ]]; then
		echo "Configuration file is not found"
		read -r -p "Create it> [y/N]" answer
		if [[ "$answer" == "y" ]]; then
			create_config
		else
			echo -e "No config file\bExiting"
			exit 2
		fi
	else
		source .git_myconfig
	fi

	if [[ -z "$USER_NAME" || -z "$USER_EMAIL" || -z "$USER_BRANCH" ]]; then
		echo "Not enough settings, check .git_myconfig file"
		exit 3
	fi

	git -C "$1" init
	git -C $1 config --local user.name "$USER_NAME"
	git -C $1 config --local user.email "$USER_EMAIL"
	git -C $1 config --local init.defaultBranch "$USER_BRANCH"
	echo "# $(basename "$1")" > "$1/README.md"
	git -C "$1" add README.md
	git -C "$1" commit -m "Initial commit"
	if [[ -n $2 ]]; then
		git -C $1 remote add origin $2
	fi
else
	echo -e "Usage:\n$0 <directory>\n$0 <directory> <remote_utl>"
fi

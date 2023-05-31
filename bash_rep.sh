#!/usr/bin/env bash
function rep {
	for ((i = 0 ; i < $2 ; i++)); do
  	printf "$1"
	done
}
rep $@	

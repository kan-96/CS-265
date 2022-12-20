#!/bin/bash
# count - print out the filename, # line of that file, and # words of that file in current directory
#
# Khoa Nguyen
# 10/9
#

echo "$USER"
for f in *; do
	if [ -f "$f" ]; then
		echo -n "$f"
		cat "$f" | wc -wl
	fi
done
exit $1

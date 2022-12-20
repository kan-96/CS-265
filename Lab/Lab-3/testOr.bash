#!/bin/bash
#organiseMusic - organise song file by name in its artist directory
#Khoa Nguyen
#10/09

for f in *.mp3 ; do
   if [ -f "$f" ] ; then
      IFS='-' read -r -a array <<< "$file" #splitting string by hyphen as delimeter
     	echo " ${array[0]}"
		echo " ${array[1]}"
		 mkdir -p "$array[0]"
      mv "$f" "${array[0]}//${array[1]}"
   fi
done


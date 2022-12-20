#!/bin/bash
#
# a1-top: create dir.json include top level keys such as index required files, other
# Khoa Nguyen
# 10/22
# GNU/Linux 5.4.0-126-generic x86_64
# EDITOR
# columns=110, tapstop=3
if (($# >1 )) ; then
	echo "Not a valid argument"
else
	currDir=${1:-$PWD}
fi
TAB='   ' #3 spaces
TABSUB='      ' #6 spaces

for dir in $(find . -type d) ; do
	dirJson=$dir"/dir.json"
	dirREADME=$dir"/README"
	index=""
	required=""
	other=""
	requiredFiles=""
	requiredDir=""
	otherFiles=""
	otherDir=""
	#Keys seraperate from README
	if [[ -e $dirREADME ]] ; then
		read index required  <<< $(awk -f parseReadme.awk $dirREADME)
	fi
	for f in $(find $dir -maxdepth 1) ; do
		if [[ *$f* != "$index $required" && $f != $dir && $f != "README" ]] ; then
			other+=${f##*/}" "
		fi
	done
	#echo $index $required $other
	#build dir.json
	echo "{" > $dirJson
	#copy index file into dir.json
	printf "$TAB\"index\": " >> $dirJson
	for f in $index; do
		if [[ $f != 0 ]] ; then
			printf "\"$f\", "	>> $dirJson
		fi
	done
	printf "\n$TAB\"required\" : {\n" >> $dirJson
	#copy required files and directory into dir.json
	for f in $required; do
		if [[ $f != 0 ]] ; then
			if [[ -d $dir"/"$f ]] ; then
				requiredDir+=${f##*/}" "
			else
				requiredFiles+=${f##*/}" "

			fi
		fi
	done
	#pase required files
	printf "$TABSUB\"files\": [" >> $dirJson
	for i in $requiredFiles; do
		printf " \"$i\"," >> $dirJson
	done
	sed -i 's/,$//' $dirJson		#trim last commna sentence
	printf "],\n" >> $dirJson
	#pase require directories
	printf "$TABSUB\"directories\" : [" >> $dirJson
	for i in $requiredDir; do
		printf " \"$i\"," >> $dirJson
	done
	sed -i 's/,$//' $dirJson		#trim last commna sentence
	printf "]\n" >> $dirJson
	printf "$TAB}," >> $dirJson 	#required's part end
	#paese other data
	printf "\n$TAB\"other\" : {\n" >> $dirJson
	for f in $other; do
		if [[ $f != 0 ]] ; then
			if [[ -d $dir"/"$f ]] ; then
				otherDir+=${f##*/}" "
			else
				otherFiles+=${f##*/}" "

			fi
		fi
	done
	#pase required files of $other
	printf "$TABSUB\"files\": [" >> $dirJson
	for f in $otherFiles; do
		printf " \"$f\"," >> $dirJson
	done
	sed -i 's/,$//' $dirJson		#trim last commna sentence
	printf "],\n" >> $dirJson
	#pase require directories
	printf "$TABSUB\"directories\" : [" >> $dirJson
	for f in $otherDir; do
		printf " \"$f\"," >> $dirJson
	done
	sed -i 's/,$//' $dirJson		#trim last commna sentence
	printf "]\n" >> $dirJson
	printf "$TAB}\n" >> $dirJson 	#other's part end
	printf "}\n" >> $dirJson
done

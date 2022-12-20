
BEGIN	{
	FS = ":"
	indexFile = ""
	requiredList = ""
}
{
	for (idx = 2 ; idx <= NF ; idx++)	{
		if ($1 == "index")	{
			indexFile =(indexFile " " $idx)
		}
		if ($1 == "required")	{
			requiredList = (requiredList " " $idx)
		}
	}
}
END	{
#make sure we collect valid data
	if (indexFile == "")	{
		indexFile = 0
	}
	if (requiredList == "")	{
		requiredList = 0
	}
	print indexFile, requiredList
}

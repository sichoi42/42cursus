#include <dirent.h>
#include <errno.h>
#include <stdio.h>

void	classify(struct dirent *file)
{
	printf("%s\t%d\t%d\t", file->d_name, file->d_ino, file->d_namlen);
	if (file->d_type == DT_BLK)
		printf("Block Device\n");
	else if (file->d_type == DT_CHR)
		printf("Character Device\n");
	else if (file->d_type == DT_DIR)
		printf("Directory\n");
	else if (file->d_type == DT_LNK)
		printf("Symbolic Link\n");
	else if (file->d_type == DT_REG)
		printf("Regular File\n");
	else if (file->d_type == DT_SOCK)
		printf("Unix Domain Socket\n");
	else
		printf("Unkown File Type\n");
}

int main(void)
{
	int	temp;
	DIR	*dirp;
	struct dirent *file;
	dirp = opendir("test_dir");
	if (!dirp)
	{
		printf("error\n");
		return (1);
	}
	while (1)
	{
		temp = errno;
		file = readdir(dirp);
		if (!file && temp != errno)
		{
			printf("error\n");
			return (1);
		}
		if (!file)
			break ;
		classify(file);
	}
	closedir(dirp);
	return (0);
}

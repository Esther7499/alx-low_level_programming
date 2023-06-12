#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * read_textfile - function that reads a text file and prints it
 * @filename: file pointer to read
 * @letters: number of letters it could read and print
 * Return: the actual number of letters it could read and print
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd_open, fd_read, fd_write;
	char *temp;

	if (filename == NULL)
		return (0);
	temp = malloc(sizeof(char) * letters);
	if (temp == NULL)
		return (0);
	fd_open = open(filename, O_RDONLY);
	if (fd_open < 0)
	{
		free(temp);
		return (0);
	}
	fd_read = read(fd_open, temp, letters);
	if (fd_read < 0)
	{
		free(temp);
		return (0);
	}
	fd_write = write(STDOUT_FILENO, temp, fd_read);
	free(temp);
	close(fd_open);
	if (fd_write < 0)
		return (0);
	return ((ssize_t)fd_write);
}

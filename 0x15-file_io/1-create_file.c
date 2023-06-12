#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * create_file - function that creates a file
 * @filename: The filename to create
 * @text_content: a NULL terminated string to write to the file
 * Return: 1 on success, -1 if file can not be created, nor written,
 * nor write fails.
 */
int create_file(const char *filename, char *text_content)
{
	int fd_open, fd_write, len = 0;

	if (filename == NULL)
		return (-1);
	fd_open = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (fd_open < 0)
		return (-1);
	while (text_content && *(text_content + len))
		len++;
	fd_write = write(fd_open, text_content, len);
	close(fd_open);
	if (fd_write < 0)
		return (-1);
	return (1);
}

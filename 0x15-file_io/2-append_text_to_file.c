#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * append_text_to_file - A function that appends text at the end to the  file
 * @filename: The filename to open and append in
 * @text_content: The NULL terminated string to add
 * Return: 1 on success, -1 if the file can not be created, nor written,
 * nor write fails.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd_open, fd_write, len = 0;

	if (filename == NULL)
		return (-1);
	fd_open = open(filename, O_RDWR | O_APPEND);
	if (fd_open < 0)
		return (-1);
	if (text_content == NULL)
	{
		close(fd_open);
		return (1);
	}
	while (*(text_content + len))
		len++;
	fd_write = write(fd_open, text_content, len);
	close(fd_open);
	if (fd_write < 0)
		return (-1);
	return (1);
}

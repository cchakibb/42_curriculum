#include "get_next_line.h"

/* //! Mandatory part
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("./file.txt", O_RDONLY);
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
 */

/* //! Bonus part
int	main(void)
{
	int		fd1;
	int		fd2;
	char	*line;

	fd1 = open("./file1.txt", O_RDONLY);
	fd2 = open("./file2.txt", O_RDONLY);
	line = get_next_line(fd1);
	printf("%s", line);
	free(line);
	line = get_next_line(fd1);
	printf("%s", line);
	free(line);
	line = get_next_line(fd2);
	printf("%s", line);
	free(line);
	line = get_next_line(fd1);
	printf("%s", line);
	free(line);
	close(fd1);
	close(fd2);
	return (0);
} */


#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("main.c", O_RDONLY);
	line = get_next_line(fd);
	int i = 5;
	while (line)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

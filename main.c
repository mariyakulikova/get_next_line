#include "get_next_line.h"

int	main(void)
{
	int		fd;
	// char	*buf = "hello\nthere!";
	char	*line;

	fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	int i = 5;
	while (i-- > 0)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

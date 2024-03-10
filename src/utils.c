void	error_message(char *text, int mode)
{
	if (mode == 0)
		perror(text);
	else if (text)
		ft_putstr_fd(text, 2);
	exit(EXIT_FAILURE);
}
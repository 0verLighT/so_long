CC = cc
NAME = so_long



fclean: clean
	rm -f $(NAME)

.PHONY: all, re, flcean, clean
all:
	clang main.c wikimedia_titles.c -lexpat -o parse

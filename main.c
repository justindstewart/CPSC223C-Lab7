/*
  main.c

  CPSC 223C
  Spring 2015
  CSU Fullerton

  Lab 7: Parsing Wikimedia XML

  Authors: Kevin Wortman (kwortman@csu.fullerton.edu)

  You should leave this file unchanged.

*/ 

#include <stdio.h>

#include "wikimedia_titles.h"

int main(int argc, char** argv) {
  
  Wikimedia_Titles* wt;
  int i;

  if (argc != 2) {
    fputs("error: you must supply an .xml filename as the only argument\n", stderr);
    return 1;
  }

  wt = wikimedia_titles_parse(argv[1]);
  if (wt == NULL) {
    return 1;
  }

  for (i = 0; i < wikimedia_titles_count(wt); i++) {
    puts(wikimedia_titles_get(wt, i));
  }

  wikimedia_titles_free(wt);

  return 0;
}

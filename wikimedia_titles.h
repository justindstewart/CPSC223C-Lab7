/*
  wikimedia_titles.h

  CPSC 223C
  Spring 2015
  CSU Fullerton

  Lab 7: Parsing Wikimedia XML

  Authors: Kevin Wortman (kwortman@csu.fullerton.edu)

  You should leave this file unchanged.

*/ 

#ifndef __WIKIMEDIA_TITLES_H
#define __WIKIMEDIA_TITLES_H

/* Opaque data type storing a collection of page title strings. */
typedef struct Wikimedia_Titles_t {
  /* partially-filled array of strings */
  char** titles;    /* array of pointers to strings */
  int title_count;  /* number of strings */
} Wikimedia_Titles;

/* Parse all title strings, contained within <title> and </title> XML
   tags, from an XML file. path should be a string containing a path
   to a Wikimedia-generated XML file, for example something like
   "galactica_pages_current.xml". On sucess, returns a pointer to a
   Wikimedia_Titles object which must eventually be freed with
   wikimedia_titles_free. On error, returns NULL and prints an error
   message to stderr. */
Wikimedia_Titles* wikimedia_titles_parse(const char* path);

/* Return the number of titles. */
int wikimedia_titles_count(Wikimedia_Titles* wt);

/* Return a pointer to one of the title strings. index must obey the
   inequality

   0 <= index < number of titles .

   The string is contained within the Wikimedia_Titles object, so the
   string should not be modified or freed. */
char* wikimedia_titles_get(Wikimedia_Titles* wt, int index);

/* Free a Wikimedia_Titles object. */
void wikimedia_titles_free(Wikimedia_Titles* wt);

#endif

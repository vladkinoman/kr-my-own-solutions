#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Getword.h"
#include "AlphaBinaryTree.h"

#define MAXWORD 100

/* Possible input 1:

To find out whether a new word is already in the tree, start at the root and compare the new
word to the word stored at that node. If they match, the question is answered affirmatively. If
the new record is less than the tree word, continue searching at the left child, otherwise at the
right child. If there is no child in the required direction, the new word is not in the tree, and in
fact the empty slot is the proper place to add the new word. This process is recursive, since
the search from any node uses a search from one of its children. Accordingly, recursive
routines for insertion and printing will be most natural.
*/

/* Possible input 2:

now is the time for all good men to come to the aid of their party
*/

int main(int argc, char const *argv[])
{
	struct tnode *root;
	char word[MAXWORD];
	root = NULL;
	int snum = 1;
	int c;
	
	while ((c = getword(word, MAXWORD)) != EOF)
	{
		if (c == '\n')
			++snum;
		if (isalpha(word[0]))
			root = addtree(root, word, snum); // we works only with root
	}

	for (int i = 0; i < 19; ++i)
		root = removetreenode(root, noisewords[i]);

	treeprint(root);
	
	return 0;
}
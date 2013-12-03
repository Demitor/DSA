
/**************************************************************/
/* DSA tree program example                                   */
/**************************************************************/
/* D.F. ROSS 121013 test version                              */
/**************************************************************/

/**************************************************************/
/* include files and  global data objects                     */
/**************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**************************************************************/
/* define constants & types                                   */
/**************************************************************/

#define ARRLEN 100
#define NILL   -1
#define NULLREF NULL

/**************************************************************/
/* tree element definition (this is hidden!)                  */
/**************************************************************/

typedef struct treenode * treeref;

typedef struct treenode {
        int        value;
        int        height;
        treeref    LC;
        treeref    RC;
        } treenode;

/**************************************************************/
/* define tree instance                                       */
/**************************************************************/

static treeref T     = (treeref) NULL;
static treeref pnew  = NULLREF;

/**************************************************************/
/* define heap array instance                                 */
/**************************************************************/

static int first=NILL,  last=NILL;
static int qfirst=NILL, qlast=NILL;

static treeref heaparr[ARRLEN];
static int queue[ARRLEN];


/****************************************************************************/
/****************************************************************************/
/* private operations on the tree - primitive operationa                    */
/****************************************************************************/
/****************************************************************************/

/****************************************************************************/
/* primitive functions                                                      */
/****************************************************************************/
/* is_empty:        treeref       --> Boolean                               */
/* get_value:       treeref       --> int                                   */
/* get_height:      treeref       --> int                                   */
/* get_LC:          treeref       --> treeref                               */
/* get_RC:          treeref       --> treeref                               */
/* set_value:       int x treeref --> treeref                               */
/* set_LC:          treeref       --> treeref                               */
/* set_RC:          treeref       --> treeref                               */
/* create_node:     int           --> treeref                               */
/****************************************************************************/

static int      is_empty(treeref T)             { return T == (treeref) NULLREF; }

static int      get_value(treeref T)            { return T->value; }
static int      get_height(treeref T)           { return T->height; }
static treeref  get_LC(treeref T)               { return T->LC; }
static treeref  get_RC(treeref T)               { return T->RC; }

static treeref  set_value(treeref T, int v)     { T->value = v; return T; }
static treeref  set_height(treeref T, int h)    { T->height = h; return T; }
static treeref  set_LC(treeref T, treeref L)    { T->LC = L; return T; }
static treeref  set_RC(treeref T, treeref R)    { T->RC = R; return T; }

/****************************************************************************/
/* create and initialise an element in the tree                             */
/****************************************************************************/

static treeref create_node(int v) 
{
	treenode *new = malloc(sizeof(treenode));
	set_value(new, v);
	set_RC(new, NULLREF);
	set_LC(new, NULLREF);
	set_height(new, NULLREF);

	//if(is_empty(T)) T = new;

	//printf("value:%d, LC%d, RC:%d, height:%d", get_value(T), get_LC(T), get_RC(T), get_height(T));

	return new; }

/****************************************************************************/
/****************************************************************************/
/* private operations on the tree - basic operationa                        */
/****************************************************************************/
/****************************************************************************/

/****************************************************************************/
/* basic functions                                                          */
/****************************************************************************/
/* cons:      treeref x treeref x treeref      --> treeref                  */
/* b_add:     int x treeref                    --> treeref                  */
/* b_rem:     int x treeref                    --> treeref                  */
/* b_find:    int x treeref                    --> Boolean                  */
/****************************************************************************/

/****************************************************************************/
/* LC, Node, RC - a RECURSIVE view of the tree                              */
/****************************************************************************/

static treeref node(treeref T)             { /* TO DO */ return NULL; }
static treeref LC(treeref T)               { /* TO DO */ return NULL; }
static treeref RC(treeref T)               { /* TO DO */ return NULL; }

/****************************************************************************/
/* CONStruct a new tree from a LC, Node and RC                              */
/****************************************************************************/

static treeref cons(treeref LC, treeref N, treeref RC) {
	set_RC(N, RC);
	set_LC(N, LC); return N; }

/****************************************************************************/
/* FIND the height of the tree                                              */
/****************************************************************************/

//static int max(int a, int b) { /* TO DO */ return 0; }

static int b_height(treeref T) 
{
	if (is_empty(T)) return 0;
	int L_height = b_height(get_LC(T));
  	int R_height = b_height(get_RC(T));
  	return (L_height > R_height) ? L_height + 1 : R_height + 1;
}

/****************************************************************************/
/* display the tree ELEMENT                                                 */
/****************************************************************************/

static void b_disp_el(treeref T) { 
	if(!is_empty(T))	printf("[%d]\n", get_value(T));
	else				printf("[nil]\n"); 
}

/****************************************************************************/
/* display the heap array                                                   */
/****************************************************************************/

static void b_disp_array() { printf("%d\n", get_value(T)); }

/****************************************************************************/
/* Tree to array via a queue (breadth-first search)                         */
/****************************************************************************/
/* Transforms a binary tree to a sequence (including NULL references)       */
/* e.g.  the following tree:                   [5]                          */
/*                                     [2]            [7]                   */
/*                               [nil]     [3]    [6]     [nil]             */
/*                                                                          */
/* becomes: [5] [2] [7] [nil] [3] [6] [nil]                                 */
/****************************************************************************/

static void T2Q(treeref T, int i) 
{
	if(!is_empty(T))
	{
		queue[i] = get_value(T);
		T2Q(get_LC(T), (i*2));
		T2Q(get_RC(T), ((i*2)+1));
	}
	/*int i = 0, current = 0, j = 0;
	queue[i] = T;
	i++;

	while(!queue[i] != NULLREF)
	{
		if(get_LC(queue[current]) == NULLREF)
		queue[i] = get_LC(queue[current]);
		i++;

		queue[i] = get_RC(queue[current]);
		i++;

		current++;
	}
	while(queue[j] != NULLREF)
	{
		printf("[%d] ", get_value(queue[j]));
		j++;
	}*/
}

/****************************************************************************/
/* display the tree in 2D                                                   */
/****************************************************************************/
/* step 1: transform the tree to an array (Q) using T2Q() above             */
/* e.g. array [5] | [2] [7] | [nil] [3] [6] [nil] | etc.                    */
/*      level (1) | (2) (2) | (3)   (3) (3) (3)   | (4) ...                 */
/* step 2: then print the nodes at each level of the tree to give           */
/* level 1 (1 node)                           [5]                           */
/* level 2 (2 nodes)                   [2]            [7]                   */
/* level 3 (4 nodes)             [nil]     [3]    [6]     [nil]             */
/****************************************************************************/

static void b_disp_2D() 
{
	T2Q(T, 1);

	int i = 1, j, temp = 2, bs = (int) pow((double)2,(double)(b_height(T)-1)), b, k = 0;
	
	while(k < b_height(T)) // Så länge som det inte är slut på kön
	{
		if(temp == 2) // Skriver ut roten
		{ 
			for(j=0;j<=bs;j++){ printf(" "); }
			printf("[%d]", queue[i]); i++; 
			b = bs;
		}
		if(temp != 2) // Skriver ut första värdet på raden
		{
			b =	b/2;
			for(j=0;j<b;j++) { printf(" "); }
			printf("[%d]", queue[i]); i++; 
		}
		while(i < temp)	// Skriver ut resterande värden på raden
		{ 
			b = (b + (bs/temp));
			for(j=0;j<=b;j++) { printf(" "); }
			printf("[%d]", queue[i]); i++; 
		}
		printf("\n");
		temp = temp*2;
		k++;
	}
	
}

/****************************************************************************/
/* display the tree (pre-order)                                             */
/****************************************************************************/

static void b_disp_pre(treeref T) { /* TO DO */ }

/****************************************************************************/
/* display the tree (in-order)                                              */
/****************************************************************************/

static void b_disp_in(treeref T) { /* TO DO */ }
/****************************************************************************/
/* display the tree (post-order)                                            */
/****************************************************************************/

static void b_disp_post(treeref T) { /* TO DO */ }

/****************************************************************************/
/* ADD to the tree in BST order                                             */
/****************************************************************************/

static treeref b_add(treeref T, treeref N) 
{
	printf("\n%p\n", T);
	if(T == (treeref)NULL){ T=N; printf("\n0\n");fflush(stdout); return N; }
	else
	{
		printf("\n1\n");fflush(stdout);
		if(get_value(N) > get_value(T) && get_RC(T) != NULLREF)
		{
			printf("2\n");fflush(stdout);
			//T = get_RC(T);
			b_add(get_RC(T),N);
		}
		else if(get_value(N) <= get_value(T) && get_LC(T) != NULLREF)
		{
			printf("3\n");fflush(stdout);
			//T = get_LC(T);
			b_add(get_LC(T),N);
		}
		else
		{
			printf("4\n");fflush(stdout);
			if(get_value(N) <= get_value(T))
			{
				printf("4.1\n");fflush(stdout);
				set_LC(T,N);
			}
			else
			{
				printf("4.2\n");fflush(stdout);
				set_RC(T,N);
			}
			
		}
	}
	printf("SLUT\n");fflush(stdout);

	return T;
}

/****************************************************************************/
/* REMove an element from the tree / BST order                              */
/****************************************************************************/

static treeref b_rem(treeref T, int v) 
{
	printf("1"); fflush(stdout);
	if(is_empty(T))	return T; 
	if(v == get_value(T))
	{	
		printf("2"); fflush(stdout);
		if(pnew != NULLREF)
			{
				if(v<pnew)
				{
					printf("3"); fflush(stdout);
					if(get_RC(T) != NULLREF && get_LC(get_RC(T)) != NULLREF)
					{
						printf("3.1"); fflush(stdout);
						treeref i = get_RC(T);
						while(get_LC(i) != NULLREF)
						{
							i = get_LC(i);
						}
						set_LC(i, get_LC(T));
						set_LC(pnew, get_RC(T));
						printf("3.2"); fflush(stdout);
					}
					else
						printf("3.3"); fflush(stdout);
						if(get_LC(T) != NULLREF)
						{
							set_LC(pnew, get_LC(T));
						}
						else	set_LC(pnew, NULLREF);					
				}
				else 
					printf("4"); fflush(stdout);
					if(get_RC(T) != NULLREF && get_LC(get_RC(T)) != NULLREF)
					{
						printf("4.1"); fflush(stdout);
						treeref i = get_RC(T);
						while(get_LC(i) != NULLREF)
						{
							i = get_LC(i);
						}
						set_LC(i, get_LC(T));
						set_LC(pnew, get_RC(T));
					}
					else
						printf("4.2"); fflush(stdout);
						if(get_LC(T) != NULLREF)
						{
							set_RC(pnew, get_RC(T));
						}
						else {set_RC(pnew, NULLREF); printf("4.3"); fflush(stdout);}
						
				pnew = NULLREF;
			}
		else if(get_RC(T) != NULLREF)
		{
			printf("5"); fflush(stdout);
			//treeref F = get_RC(T);

			printf("5.0"); fflush(stdout);

			if(get_LC(get_RC(T)) != NULLREF)
			{
				printf("5.1"); fflush(stdout);
				treeref i = get_RC(T);
				while(get_LC(i) != NULLREF)
				{
					i = get_LC(i);
				}

				set_LC(i, get_LC(T));
			}
			else
			{
				printf("5.2"); fflush(stdout);
				set_LC(get_RC(T), get_LC(T));
			}
			pnew = NULLREF;
			printf("5.3"); fflush(stdout);

		}
		else
		{
			T= NULLREF;
			printf("5.4"); fflush(stdout);
		}
		printf("6"); fflush(stdout);
	}
	if(v < get_value(T)){	pnew = T; printf("7"); fflush(stdout);	return b_rem(get_LC(T), v);	}
	if(v > get_value(T)){	pnew = T; printf("8"); fflush(stdout);	return b_rem(get_RC(T), v);	}
}

/****************************************************************************/
/* Build heap tree                                                          */
/****************************************************************************/

static void build_HT() { /* TO DO */ }

/****************************************************************************/
/* ADD to the tree in heap order                                            */
/****************************************************************************/

static treeref b_addh(treeref N) { /* TO DO */ return NULL; }

/****************************************************************************/
/* REMove an element from the tree in heap order                            */
/****************************************************************************/

static treeref b_remh(int v) { /* TO DO */ return NULL; }

/****************************************************************************/
/* FIND an element in the BST (Binary Search Tree)                          */
/****************************************************************************/

static int b_findb(treeref T, int v) {
	
	return 	is_empty(T)			?	NULL
		:	get_value(T)==v 	?	T
		:	get_value(T)<v 		?	b_findb(get_RC(T), v)
		:							b_findb(get_LC(T), v);



	/*if(T==V){
	printf("Node [%d] found, on height: %d.",v ,get_height(T));
}else{
	if (T < v)
	{
		if (get_RC(T) != NULLREF)
		{
			T = get_RC(T);
			b_findb(T, v);
		}
		else{
			printf("Node not found\n");
		}
	}
	if (T > v)
	{
		if (get_LC(T) != NULLREF)
		{
			T = get_LC(T);
			b_findb(T, v);
		}
		else{
			printf("Node not found\n");
		}
	}

	}
	
 return 0;*/ }

/****************************************************************************/
/* FIND an element in the complete tree                                     */
/****************************************************************************/

static int b_findc(treeref T, int v) { /* TO DO */ return 0; }

/****************************************************************************/
/* FIND the number of element in the tree (cardinality)                     */
/****************************************************************************/

static int b_card(treeref T) { return 0; /* TO DO */ return 0; }


/****************************************************************************/
/* Heapify the tree (heap)                                                  */
/****************************************************************************/

static treeref b_heapify(treeref T) { return T; /* TO DO */ return NULL; }

/****************************************************************************/
/****************************************************************************/
/* public operations on the tree                                            */
/****************************************************************************/
/****************************************************************************/

void disp_2D()                { b_disp_2D();   }
void disp_array()             { b_disp_array();  }

void disp_pre()               { b_disp_pre(T);  }
void disp_in()                { b_disp_in(T);   }
void disp_post()              { b_disp_post(T); }

void add(int v)               { T = b_add(T, create_node(v)); }
void rem(int v)               { T = b_rem(T, v); }

void addh(int v)              { T = b_addh(create_node(v)); }
void remh(int v)              { T = b_remh(v); }

int is_memberb(int v)         { return b_findb(T, v); }
int is_memberc(int v)         { return b_findc(T, v); }

int cardinality()             { return b_card(T); }
int bheight()                 { return b_height(T); }

void bheapify()               { T = b_heapify(T); }

/****************************************************************************/
/* end of basic functions                                                   */
/****************************************************************************/




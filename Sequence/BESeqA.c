
/**************************************************************/
/* DSA list program example                                   */
/**************************************************************/
/* D.F. ROSS 120627 test version                              */
/**************************************************************/

/**************************************************************/
/* include files and  global data objects                     */
/**************************************************************/

#include <stdio.h>
#include <stdlib.h>

/****************************************************************************/
/* define types & constants                                                 */
/****************************************************************************/

#define   LSIZE        20               /* max number of list elements      */
#define   NULLREF      -1               /* null reference for list          */

typedef  int          listref;          /* list element reference type      */

/****************************************************************************/
/*  Define list structure                                                   */
/****************************************************************************/

int     value[LSIZE];                 /* list values                        */
listref next[LSIZE];                  /* list next references               */
listref prev[LSIZE];                  /* list prev references               */

/****************************************************************************/
/* define list instance recursive/iterative                                 */
/****************************************************************************/

static listref  liststart = NULLREF;         /* ref to start of list        */
static listref  listend   = NULLREF;         /* ref to end of list          */

static listref  pcurr     = NULLREF;         /* ref to the current element  */
/*static listref  pprev     = NULLREF;*/         /* ref to the previous element */
static listref  pnew      = NULLREF;         /* ref to the new element      */

static int      numels    = 0;               /* number of elements          */

/****************************************************************************/
/****************************************************************************/
/* private operations on the list - primitive operationa                    */
/****************************************************************************/
/****************************************************************************/

/****************************************************************************/
/* primitive functions                                                      */
/****************************************************************************/
/* is_empty:        listref            --> Boolean                          */
/* get_value:       listref            --> int                              */
/* get_next:        listref            --> listref                          */
/* get_prev:        listref            --> listref                          */
/* set_value:       int x listref      --> listref                          */
/* set_next:        listref x listref  --> listref                          */
/* set_prev:        listref x listref  --> listref                          */
/* create_e:        int                --> listref                          */
/****************************************************************************/

static int      is_empty(listref L)             { return L==NULLREF; }

static int      get_value(listref E)            { return value[E]; }
static listref  get_next(listref E)             { return next[E]; }
static listref  get_prev(listref E)             { return prev[E]; }

static void     set_value(listref E, int v)     { value[E] = v; }
static void     set_next(listref E, listref t)  { next[E] = t; }
static void     set_prev(listref E, listref t)  { prev[E] = t; }



/****************************************************************************/
/* create and initialise an element in the list                             */
/****************************************************************************/

static listref create_e(int v) 
{
	
	if(numels == LSIZE)
	{
		int i = 0;
		while(get_next(i) != get_prev(i) && i < LSIZE){ i++; }

		set_value(i, v);
		set_next(i, NULLREF);
		set_prev(i, NULLREF);
		pnew = i;
	}
	else
	{
		set_value(numels, v);
		set_next(numels, NULLREF);
		set_prev(numels, NULLREF);
		pnew = numels;
	}
	
	numels++;


return pnew; 
}

/****************************************************************************/
/****************************************************************************/
/* private operations on the list - basic operations                        */
/****************************************************************************/
/****************************************************************************/

/****************************************************************************/
/* basic functions                                                          */
/****************************************************************************/
/* b_add:     int x listref          --> listref                            */
/* b_addpos:  int x listref x pos    --> listref                            */
/* b_rem:     int x listref          --> listref                            */
/* b_rempos:  int x listref x pos    --> listref                            */
/* b_find:    int x listref          --> listref                            */
/****************************************************************************/

/****************************************************************************/
/* display the list                                                         */
/* e.g. for list (1, 2, 5, 7, 9) gives List: 1 2 5 7 9 EOL                  */
/****************************************************************************/

static void b_disp() 
{
	pcurr = liststart;
	

	if(get_prev(liststart) == NULLREF) // Används om arrayen inte är tom
	{
		
		// Skriver ut första värdet i arrayen
		printf("-%d-,\t", get_value(liststart));
		
		// Skriver ut resterande värden i arrayen (i ordning)
		if(get_next(liststart) != NULLREF)
		{
			pcurr = get_next(liststart);
			while(get_next(pcurr) != NULLREF)
			{
				printf("-%d-,\t", get_value(pcurr));
				pcurr = get_next(pcurr);									
			}
			printf("-%d-", get_value(pcurr));
		}
		
	}
}

/****************************************************************************/
/* ADD to the list in ascending order by value                              */
/* e.g. b_add(4) on list (1, 2, 5, 7, 9) gives (1, 2, 4, 5, 7, 9)           */
/****************************************************************************/

static void b_add(int v) { 

	
	// Lägger till ett element
	create_e(v);
	

	if(numels == 1) // När första elementet lagts till sätts liststart och listend till 0 
	{
		liststart = 0;
		listend = 0;
	}
 	
	if(numels >1) // Om fler än ett element finns i listan
	{
		pcurr = liststart; //, j = numels-1;

	
		//Hittar positionen där v skall placeras
		while(v > get_value(pcurr) && pcurr != listend) 
		{												  
			pcurr = get_next(pcurr);
		}												  


		// Lägger in next och prev värden för v och värdena runt om, före eller efter
		if(v < get_value(listend) && v > get_value(liststart)) // Om talet skall läggas till mellan två tal
		{
			set_next(pnew, pcurr);
			set_prev(pnew, get_prev(pcurr));

			set_next(get_prev(pcurr), pnew);
			set_prev(pcurr, pnew);	
		}
		else if(v < get_value(liststart) || v == get_value(pcurr)) // Om talet skall ligga först
		{
			if(v != get_value(get_prev(pcurr)))
			{
				set_next(get_prev(pcurr), pnew);
				set_prev(pnew, get_prev(pcurr));
			}

			set_next(pnew, pcurr);
			set_prev(pcurr, pnew);
		}
		else if(v > get_value(listend))	// Om talet skall ligga sist
		{
			set_prev(pnew, pcurr);
			set_next(pcurr, pnew);
		}

		
		if(get_prev(pnew) == NULLREF) // Sätter liststart till lägsta värdet
		{
			liststart = pnew;
		}

		if(get_next(pnew) == NULLREF) // Sätter listend till största värdet
		{
			listend = pnew;
		}
		

		printf("\n###################################################\n");
		printf("***                                             ***\n");
		printf("***                 ARRAYEN                     ***\n");
		printf("***                                             ***\n");
		printf("***\t-Värdet på plats %d är lika med: %d\t***\n", pnew, get_value(pnew));																   
		printf("***\t-next: %d\t\t\t\t***\n", get_next(pnew));
		printf("***\t-prev: %d\t\t\t\t***\n", get_prev(pnew));
		printf("***\t-liststart: %d\t\t\t\t***\n", liststart);
		printf("***                                             ***\n");
		printf("###################################################\n");
	}
	
	
}
/****************************************************************************/
/* Add a new element at position p of the list                              */
/* the legal positions are 1..size(list)+1                                  */
/* otherwise give an error message - Error: invalid position                */
/* i.e. for a list of 5 elements positions: 1,2,3,4,5                       */
/* e.g. b_addpos(8, 0) on (1, 3, 5, 7, 9) gives Error: invalid position     */
/* e.g. b_addpos(8, 1) on (1, 3, 5, 7, 9) gives (8, 1, 3, 5, 7, 9)          */
/* e.g. b_addpos(8, 2) on (1, 3, 5, 7, 9) gives (1, 8, 3, 5, 7, 9)          */
/* e.g. b_addpos(8, 5) on (1, 3, 5, 7, 9) gives (1, 3, 5, 7, 8, 9)          */
/* e.g. b_addpos(8, 6) on (1, 3, 5, 7, 9) gives (1, 3, 5, 7, 9, 8)          */
/* e.g. b_addpos(8, 7) on (1, 3, 5, 7, 9) gives Error: invalid position     */
/****************************************************************************/

static void b_addpos(int v, int pos) 
{

	create_e(v);	// Skapar elementet

	if(numels == 1) // När första elementet lagts till sätts liststart och listend till 0  
	{
		liststart = 0;
		listend = 0;
	}

	if(numels >1) // Om fler än ett element finns i listan
	{
		int i = 0;
		int pcurr = liststart;

		while(i < pos-1 && pcurr != listend) // Hittar positionen som värdet skall ligga på i arrayen
		{
			pcurr = get_next(pcurr);
			i++;
		}

		// Initierar next och prev- värden för de olika platserna
		if(pcurr == listend) // Om värdet skall läggas till efter listans värden
		{
			set_next(pnew, get_next(pcurr));
			set_prev(pnew, pcurr);

			set_next(pcurr, pnew);
		}
		else // Om värdet skall läggas till på befintliga värdens platser
		{
			set_next(pnew, pcurr);
			set_prev(pnew, get_prev(pcurr));

			if(pos > 1) // Om man lägger till värdet på annan position än den första
			{
				set_next(get_prev(pcurr), pnew);
			}
			set_prev(pcurr, pnew);
		}

		if(get_prev(pnew) == NULLREF)
		{
			liststart = pnew;
		}

		if(get_next(pnew) == NULLREF)
		{
			listend = pnew;
		}
		

		printf("\n###################################################\n");
		printf("***                                             ***\n");
		printf("***                 ARRAYEN                     ***\n");
		printf("***                                             ***\n");
		printf("***\t-Värdet på plats %d är lika med: %d\t***\n", pnew, get_value(pnew));																   
		printf("***\t-next: %d\t\t\t\t***\n", get_next(pnew));
		printf("***\t-prev: %d\t\t\t\t***\n", get_prev(pnew));
		printf("***\t-liststart: %d\t\t\t\t***\n", liststart);
		printf("***                                             ***\n");
		printf("###################################################\n");

	}
}

/****************************************************************************/
/* REMove an element from the list by value: first occurrence for duplicates*/
/* if the value is not in the list: Error: value not in list                */
/* e.g. b_rem(4) on list (1, 2, 4, 7, 9) gives (1, 2, 7, 9)                 */
/* e.g. b_rem(4) on list (1, 4, 4, 7, 9) gives (1, 4, 7, 9)                 */
/* e.g. b_rem(4) on list (1, 2, 5, 7, 9) gives Error: value not in list     */
/****************************************************************************/

static void b_rem(int v) 
{
	pcurr = liststart;
	while(v != get_value(pcurr) && pcurr != listend)	// Hittar värdet som skall tas bort
	{
		pcurr = get_next(pcurr);
	}

	if(get_value(pcurr) == v)	// Om värdet finns i listan
	{
		if((v > get_value(liststart) && v < get_value(listend)) || (pcurr != liststart && get_value(pcurr) == get_value(get_next(pcurr)))) // Om värdet som skall tas bort ligger mellan två tal
		{
			set_next(get_prev(pcurr), get_next(pcurr));
			set_prev(get_next(pcurr), get_prev(pcurr));

			set_next(pcurr, NULLREF);
			set_prev(pcurr, NULLREF);
		}
		else if(v == get_value(liststart))	// Om första värdet skall tas bort
		{
			liststart = get_next(pcurr);
			set_prev(get_next(pcurr), NULLREF);

			set_next(pcurr, NULLREF);
			set_prev(pcurr, NULLREF);
		}
		else if(v == get_value(listend))	// Om sista värdet skall tas bort
		{
			listend = get_prev(pcurr);
			set_next(get_prev(pcurr), NULLREF);

			set_next(pcurr, NULLREF);
			set_prev(pcurr, NULLREF);
		}

		numels--;
	}
	else	//Om värdet inte finns i listan
	{
		printf("Error: value not in list\n");
	}
}

/****************************************************************************/
/* REMove an element from position p of the list                            */
/* the legal positions are 1..size(list)  otherwise give an error message   */
/* e.g. b_rempos(0) on (1, 3, 5, 7, 9) gives Error: invalid position        */
/* e.g. b_rempos(2) on (1, 3, 5, 7, 9) gives (1, 5, 7, 9)                   */
/* e.g. b_rempos(5) on (1, 3, 5, 7, 9) gives (1, 3, 5, 7)                   */
/* e.g. b_rempos(6) on (1, 3, 5, 7, 9) gives Error: invalid position        */
/****************************************************************************/

static void b_rempos(int pos) 
{
	pcurr = liststart;
	int i = 0;

	while(i != pos-1)	// Hittar positionen i listan
	{
		pcurr = get_next(pcurr);
		i++; 
	}

	if(pcurr != liststart && pcurr != listend) // Om värdet som skall tas bort ligger mellan två tal
		{
			set_next(get_prev(pcurr), get_next(pcurr));
			set_prev(get_next(pcurr), get_prev(pcurr));

			set_next(pcurr, NULLREF);
			set_prev(pcurr, NULLREF);
		}
		else if(pcurr == liststart)	// Om första värdet skall tas bort
		{
			liststart = get_next(pcurr);
			set_prev(get_next(pcurr), NULLREF);

			set_next(pcurr, NULLREF);
			set_prev(pcurr, NULLREF);
		}
		else if(pcurr == listend)	// Om sista värdet skall tas bort
		{
			listend = get_prev(pcurr);
			set_next(get_prev(pcurr), NULLREF);

			set_next(pcurr, NULLREF);
			set_prev(pcurr, NULLREF);
		}

		numels--;
}

/****************************************************************************/
/* FIND an element in the list                                              */
/* FOUND:     return a reference to the element                             */
/* NOT FOUND: return NULLREF                                                */
/* e.g. b_find(4) in (1, 3, 4, 6) return reference(4)                       */
/* e.g. b_find(5) in (1, 3, 4, 6) return NULLREF                            */
/****************************************************************************/

static listref b_find(int v) 
{	
	int i = 1;	// Används för att skriva ut vilken plats i listan som värdet ligger på
	pcurr = liststart;
	
	// Söker efter värdet i listan
	while(get_next(pcurr) != NULLREF && get_value(pcurr) != v)
	{
		pcurr = get_next(pcurr);
		i++;
	}

	if(get_value(get_next(pcurr)) == v) // Om värdet finns i listan fast inte på första platsen
	{
		return printf(" värdet ligger på plats %d i listan\n", i);
	}
	else if(get_value(pcurr) == v) // Om det är första värdet i listan
	{
		return printf(" värdet ligger på plats %d i listan\n", i);
	}
	else
	{
	return NULLREF;
	} 
}

/****************************************************************************/
/* FIND the number of elements in the list (cardinality)                    */
/* e.g. for list (1, 3, 5, 7) b_card returns 4                              */
/* e.g. empty list ()         b_card returns 0                              */
/****************************************************************************/

static int b_card() { return numels; }

/****************************************************************************/
/* navigation & display functions                                           */
/****************************************************************************/
/* b_disp_C:     void --> void  (side effect)                               */
/* e.g. for list (1,3,5,7) and pcurr refers to value 3 display 3            */
/* e.g. IF pcurr is NULLREF display Error: invalid element                  */
/* b_first:      void --> void  (side effect)                               */
/* e.g. for list (1,3,5,7) set pcurr to refer to 1                          */
/* b_next:       void --> void  (side effect)                               */
/* e.g. for list (1,3,5,7) and pcurr is 1 set pcurr to refer to 3           */
/* b_exist_e:    void --> int                                               */
/* e.g. if pcurr == NULLREF return FALSE                                    */
/* e.g. if pcurr != NULLREF return TRUE                                     */
/****************************************************************************/

static void b_disp_C()  { printf("pcurr: %d\t", get_value(pcurr)); }  /* display current element (pcurr) */
static void b_first()   { printf("first: %d\t", get_value(liststart)); }
static void b_next()    { pcurr = get_next(pcurr); }
static int  b_exist_e() { return (pcurr == NULLREF) ? 0:1; }

/****************************************************************************/
/****************************************************************************/
/* public operations on the list                                            */
/****************************************************************************/
/****************************************************************************/

void disp()                   { b_disp(); }

void add(int v)               { b_add(v); }
void addpos(int v, int pos)   { b_addpos(v, pos); }

void rem(int v)               { b_rem(v); }
void rempos(int pos)          { b_rempos(pos); }

int is_member(int v)          { return !is_empty(b_find(v)); }
int cardinality()             { return b_card(); }

void bfirst()                 { b_first();   }
void bnext()                  { b_next();    }
void disp_C()                 { b_disp_C();  }
int  exist_e()                { return b_exist_e(); }

/****************************************************************************/
/* end of basic functions                                                   */
/****************************************************************************/
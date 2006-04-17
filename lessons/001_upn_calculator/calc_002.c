/* Generated by re2c */
#line 1 "calc_002.re"
/* re2c lesson 001_upn_calculator, calc_002, (c) M. Boerger 2006 */
#line 19 "calc_002.re"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int fill(char *p, int n, char **l)
{
	while (*++p && n--) ;
	* l = p;
	return n <= 0;
}

int scan(char *s)
{
	char *p = s;
	char *l = s;
	char *q = 0;
	#define YYCTYPE         char
	#define YYCURSOR        p
	#define YYLIMIT         l
	#define YYMARKER        q
	#define YYFILL(n)		{ if (!fill(p, n, &l)) break; }
	
	for(;;)
	{

#line 32 "<stdout>"
		{
			YYCTYPE yych;

			if((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
			yych = *YYCURSOR;
			switch(yych){
			case 0x00:	goto yy10;
			case '+':	goto yy6;
			case '-':	goto yy8;
			case '0':	goto yy2;
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto yy4;
			default:	goto yy12;
			}
yy2:
			++YYCURSOR;
			switch((yych = *YYCURSOR)) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto yy16;
			default:	goto yy3;
			}
yy3:
#line 48 "calc_002.re"
			{ printf("Num\n");	continue; }
#line 72 "<stdout>"
yy4:
			++YYCURSOR;
			yych = *YYCURSOR;
			goto yy15;
yy5:
#line 47 "calc_002.re"
			{ printf("Num\n");	continue; }
#line 80 "<stdout>"
yy6:
			++YYCURSOR;
#line 49 "calc_002.re"
			{ printf("+\n");	continue; }
#line 85 "<stdout>"
yy8:
			++YYCURSOR;
#line 50 "calc_002.re"
			{ printf("+\n");	continue; }
#line 90 "<stdout>"
yy10:
			++YYCURSOR;
#line 51 "calc_002.re"
			{ printf("EOF\n");	return 0; }
#line 95 "<stdout>"
yy12:
			++YYCURSOR;
#line 52 "calc_002.re"
			{ printf("ERR\n");	return 1; }
#line 100 "<stdout>"
yy14:
			++YYCURSOR;
			if(YYLIMIT == YYCURSOR) YYFILL(1);
			yych = *YYCURSOR;
yy15:
			switch(yych){
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto yy14;
			default:	goto yy5;
			}
yy16:
			++YYCURSOR;
			if(YYLIMIT == YYCURSOR) YYFILL(1);
			yych = *YYCURSOR;
			switch(yych){
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto yy16;
			default:	goto yy18;
			}
yy18:
#line 46 "calc_002.re"
			{ printf("Oct\n");	continue; }
#line 139 "<stdout>"
		}
#line 53 "calc_002.re"

	}
	printf("OOD\n"); return 2;
}

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		return scan(argv[1]);
	}
	else
	{
		fprintf(stderr, "%s <expr>\n", argv[0]);
		return 0;
	}
}

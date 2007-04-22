/* Generated by re2c 0.11.1.dev on Sat Apr 21 11:15:09 2007 */
#line 1 "scanner.re"
/* $Id$ */
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include "scanner.h"
#include "parser.h"
#include "y.tab.h"
#include "globals.h"
#include "dfa.h"

extern YYSTYPE yylval;

#ifndef MAX
#define MAX(a,b) (((a)>(b))?(a):(b))
#endif

#define	BSIZE	8192

#define	YYCTYPE		unsigned char
#define	YYCURSOR	cursor
#define	YYLIMIT		lim
#define	YYMARKER	ptr
#define YYCTXMARKER ctx
#define	YYFILL(n)	{cursor = fill(cursor);}

#define	RETURN(i)	{cur = cursor; return i;}

namespace re2c
{

Scanner::Scanner(std::istream& i, std::ostream& o)
	: in(i)
	, out(o)
	, bot(NULL), tok(NULL), ptr(NULL), cur(NULL), pos(NULL), lim(NULL)
	, top(NULL), eof(NULL), ctx(NULL), tchar(0), tline(0), cline(1), iscfg(0)
{
	;
}

char *Scanner::fill(char *cursor)
{
	if(!eof)
	{
		uint cnt = tok - bot;
		if(cnt)
		{
			memcpy(bot, tok, lim - tok);
			tok = bot;
			ptr -= cnt;
			cursor -= cnt;
			pos -= cnt;
			lim -= cnt;
		}
		if((top - lim) < BSIZE)
		{
			char *buf = new char[(lim - bot) + BSIZE];
			memcpy(buf, tok, lim - tok);
			tok = buf;
			ptr = &buf[ptr - bot];
			cursor = &buf[cursor - bot];
			pos = &buf[pos - bot];
			lim = &buf[lim - bot];
			top = &lim[BSIZE];
			delete [] bot;
			bot = buf;
		}
		in.read(lim, BSIZE);
		if((cnt = in.gcount()) != BSIZE)
		{
			eof = &lim[cnt];
			*eof++ = '\0';
		}
		lim += cnt;
	}
	return cursor;
}

#line 98 "scanner.re"


int Scanner::echo()
{
	char *cursor = cur;
	bool ignore_eoc = false;
	int  ignore_cnt = 0;

	if (eof && cursor == eof) // Catch EOF
	{
		return 0;
	}
	
	tok = cursor;
echo:
{

#line 100 "scanner.cc"
	{
		YYCTYPE yych;
		unsigned int yyaccept = 0;

		if((YYLIMIT - YYCURSOR) < 16) YYFILL(16);
		yych = *YYCURSOR;
		if(yych <= ')') {
			if(yych <= 0x00) goto yy7;
			if(yych == 0x0A) goto yy5;
			goto yy9;
		} else {
			if(yych <= '*') goto yy4;
			if(yych != '/') goto yy9;
		}
		yyaccept = 0;
		yych = *(YYMARKER = ++YYCURSOR);
		if(yych == '*') goto yy16;
yy3:
#line 204 "scanner.re"
		{
					goto echo;
				}
#line 123 "scanner.cc"
yy4:
		yych = *++YYCURSOR;
		if(yych == '/') goto yy10;
		goto yy3;
yy5:
		++YYCURSOR;
#line 180 "scanner.re"
		{
					if (ignore_eoc)
					{
						ignore_cnt++;
					}
					else
					{
						out.write((const char*)(tok), (const char*)(cursor) - (const char*)(tok));
					}
					tok = pos = cursor;
					cline++;
					goto echo;
				}
#line 144 "scanner.cc"
yy7:
		++YYCURSOR;
#line 193 "scanner.re"
		{
					if (!ignore_eoc)
					{
						out.write((const char*)(tok), (const char*)(cursor) - (const char*)(tok) - 1);
						// -1 so we don't write out the \0
					}
					if(cursor == eof)
					{
						RETURN(0);
					}
				}
#line 159 "scanner.cc"
yy9:
		yych = *++YYCURSOR;
		goto yy3;
yy10:
		yyaccept = 1;
		yych = *(YYMARKER = ++YYCURSOR);
		if(yych == 0x0A) goto yy14;
		if(yych == 0x0D) goto yy12;
yy11:
#line 163 "scanner.re"
		{
					if (ignore_eoc)
					{
						if (ignore_cnt)
						{
							out << "\n" << sourceFileInfo;
						}
						ignore_eoc = false;
						ignore_cnt = 0;
					}
					else
					{
						out.write((const char*)(tok), (const char*)(cursor) - (const char*)(tok));
					}
					tok = pos = cursor;
					goto echo;
				}
#line 187 "scanner.cc"
yy12:
		yych = *++YYCURSOR;
		if(yych == 0x0A) goto yy14;
yy13:
		YYCURSOR = YYMARKER;
		if(yyaccept <= 0) {
			goto yy3;
		} else {
			goto yy11;
		}
yy14:
		++YYCURSOR;
#line 145 "scanner.re"
		{
					cline++;
					if (ignore_eoc)
					{
						if (ignore_cnt)
						{
							out << sourceFileInfo;
						}
						ignore_eoc = false;
						ignore_cnt = 0;
					}
					else
					{
						out.write((const char*)(tok), (const char*)(cursor) - (const char*)(tok));
					}
					tok = pos = cursor;
					goto echo;
				}
#line 219 "scanner.cc"
yy16:
		yych = *++YYCURSOR;
		if(yych != '!') goto yy13;
		yych = *++YYCURSOR;
		switch(yych) {
		case 'g':	goto yy19;
		case 'i':	goto yy18;
		case 'm':	goto yy20;
		case 'r':	goto yy21;
		default:	goto yy13;
		}
yy18:
		yych = *++YYCURSOR;
		if(yych == 'g') goto yy47;
		goto yy13;
yy19:
		yych = *++YYCURSOR;
		if(yych == 'e') goto yy34;
		goto yy13;
yy20:
		yych = *++YYCURSOR;
		if(yych == 'a') goto yy26;
		goto yy13;
yy21:
		yych = *++YYCURSOR;
		if(yych != 'e') goto yy13;
		yych = *++YYCURSOR;
		if(yych != '2') goto yy13;
		yych = *++YYCURSOR;
		if(yych != 'c') goto yy13;
		++YYCURSOR;
#line 114 "scanner.re"
		{
					if (bUsedYYMaxFill && bSinglePass)
					{
						fatal("found scanner block after YYMAXFILL declaration");
					}
					out.write((const char*)(tok), (const char*)(&cursor[-7]) - (const char*)(tok));
					tok = cursor;
					RETURN(1);
				}
#line 261 "scanner.cc"
yy26:
		yych = *++YYCURSOR;
		if(yych != 'x') goto yy13;
		yych = *++YYCURSOR;
		if(yych != ':') goto yy13;
		yych = *++YYCURSOR;
		if(yych != 'r') goto yy13;
		yych = *++YYCURSOR;
		if(yych != 'e') goto yy13;
		yych = *++YYCURSOR;
		if(yych != '2') goto yy13;
		yych = *++YYCURSOR;
		if(yych != 'c') goto yy13;
		++YYCURSOR;
#line 123 "scanner.re"
		{
					if (bUsedYYMaxFill)
					{
						fatal("cannot generate YYMAXFILL twice");
					}
					out << "#define YYMAXFILL " << maxFill << std::endl;
					tok = pos = cursor;
					ignore_eoc = true;
					bUsedYYMaxFill = true;
					goto echo;
				}
#line 288 "scanner.cc"
yy34:
		yych = *++YYCURSOR;
		if(yych != 't') goto yy13;
		yych = *++YYCURSOR;
		if(yych != 's') goto yy13;
		yych = *++YYCURSOR;
		if(yych != 't') goto yy13;
		yych = *++YYCURSOR;
		if(yych != 'a') goto yy13;
		yych = *++YYCURSOR;
		if(yych != 't') goto yy13;
		yych = *++YYCURSOR;
		if(yych != 'e') goto yy13;
		yych = *++YYCURSOR;
		if(yych != ':') goto yy13;
		yych = *++YYCURSOR;
		if(yych != 'r') goto yy13;
		yych = *++YYCURSOR;
		if(yych != 'e') goto yy13;
		yych = *++YYCURSOR;
		if(yych != '2') goto yy13;
		yych = *++YYCURSOR;
		if(yych != 'c') goto yy13;
		++YYCURSOR;
#line 134 "scanner.re"
		{
					tok = pos = cursor;
					genGetState(out, topIndent, 0);
					ignore_eoc = true;
					goto echo;
				}
#line 320 "scanner.cc"
yy47:
		yych = *++YYCURSOR;
		if(yych != 'n') goto yy13;
		yych = *++YYCURSOR;
		if(yych != 'o') goto yy13;
		yych = *++YYCURSOR;
		if(yych != 'r') goto yy13;
		yych = *++YYCURSOR;
		if(yych != 'e') goto yy13;
		yych = *++YYCURSOR;
		if(yych != ':') goto yy13;
		yych = *++YYCURSOR;
		if(yych != 'r') goto yy13;
		yych = *++YYCURSOR;
		if(yych != 'e') goto yy13;
		yych = *++YYCURSOR;
		if(yych != '2') goto yy13;
		yych = *++YYCURSOR;
		if(yych != 'c') goto yy13;
		++YYCURSOR;
#line 140 "scanner.re"
		{
					tok = pos = cursor;
					ignore_eoc = true;
					goto echo;
				}
#line 347 "scanner.cc"
	}
}
#line 207 "scanner.re"

}


int Scanner::scan()
{
	char *cursor = cur;
	uint depth;

scan:
	tchar = cursor - pos;
	tline = cline;
	tok = cursor;
	if (iscfg == 1)
	{
		goto config;
	}
	else if (iscfg == 2)
	{
		goto value;
	}
{
	static const unsigned char yybm[] = {
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 122,   8, 112, 112, 120, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		122, 112,  48, 112, 112, 112, 112,  80, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		244, 244, 244, 244, 244, 244, 244, 244, 
		244, 244, 112, 112, 112, 112, 112, 112, 
		112, 116, 116, 116, 116, 116, 116, 116, 
		116, 116, 116, 116, 116, 116, 116, 116, 
		116, 116, 116, 116, 116, 116, 116, 116, 
		116, 116, 116, 112,   0,  96, 112, 116, 
		112, 116, 116, 116, 116, 116, 116, 116, 
		116, 116, 116, 116, 116, 116, 116, 116, 
		116, 116, 116, 116, 116, 116, 116, 116, 
		116, 116, 116, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
		112, 112, 112, 112, 112, 112, 112, 112, 
	};

#line 408 "scanner.cc"
	{
		YYCTYPE yych;
		unsigned int yyaccept = 0;
		if((YYLIMIT - YYCURSOR) < 5) YYFILL(5);
		yych = *YYCURSOR;
		if(yych <= '/') {
			if(yych <= '"') {
				if(yych <= 0x0C) {
					if(yych <= 0x08) goto yy87;
					if(yych <= 0x09) goto yy81;
					if(yych <= 0x0A) goto yy83;
					goto yy87;
				} else {
					if(yych <= 0x1F) {
						if(yych <= 0x0D) goto yy85;
						goto yy87;
					} else {
						if(yych <= ' ') goto yy81;
						if(yych <= '!') goto yy87;
						goto yy66;
					}
				}
			} else {
				if(yych <= '*') {
					if(yych <= '&') goto yy87;
					if(yych <= '\'') goto yy68;
					if(yych <= ')') goto yy73;
					goto yy64;
				} else {
					if(yych <= ',') {
						if(yych <= '+') goto yy74;
						goto yy73;
					} else {
						if(yych <= '-') goto yy87;
						if(yych <= '.') goto yy79;
						goto yy62;
					}
				}
			}
		} else {
			if(yych <= '\\') {
				if(yych <= '>') {
					if(yych <= ':') goto yy87;
					if(yych == '<') goto yy72;
					goto yy73;
				} else {
					if(yych <= '@') {
						if(yych <= '?') goto yy74;
						goto yy87;
					} else {
						if(yych <= 'Z') goto yy78;
						if(yych <= '[') goto yy70;
						goto yy73;
					}
				}
			} else {
				if(yych <= 'q') {
					if(yych == '_') goto yy78;
					if(yych <= '`') goto yy87;
					goto yy78;
				} else {
					if(yych <= 'z') {
						if(yych <= 'r') goto yy76;
						goto yy78;
					} else {
						if(yych <= '{') goto yy60;
						if(yych <= '|') goto yy73;
						goto yy87;
					}
				}
			}
		}
yy60:
		yyaccept = 0;
		yych = *(YYMARKER = ++YYCURSOR);
		if(yych <= '/') {
			if(yych == ',') goto yy133;
		} else {
			if(yych <= '0') goto yy130;
			if(yych <= '9') goto yy131;
		}
yy61:
#line 229 "scanner.re"
		{
					depth = 1;
					goto code;
				}
#line 496 "scanner.cc"
yy62:
		++YYCURSOR;
		if((yych = *YYCURSOR) == '*') goto yy128;
yy63:
#line 282 "scanner.re"
		{
					RETURN(*tok);
				}
#line 505 "scanner.cc"
yy64:
		++YYCURSOR;
		if((yych = *YYCURSOR) == '/') goto yy126;
#line 286 "scanner.re"
		{
					yylval.op = *tok;
					RETURN(STAR);
				}
#line 514 "scanner.cc"
yy66:
		yyaccept = 1;
		yych = *(YYMARKER = ++YYCURSOR);
		if(yych != 0x0A) goto yy122;
yy67:
#line 256 "scanner.re"
		{
					fatal("unterminated string constant (missing \")");
				}
#line 524 "scanner.cc"
yy68:
		yyaccept = 2;
		yych = *(YYMARKER = ++YYCURSOR);
		if(yych != 0x0A) goto yy117;
yy69:
#line 259 "scanner.re"
		{
					fatal("unterminated string constant (missing ')");
				}
#line 534 "scanner.cc"
yy70:
		yyaccept = 3;
		yych = *(YYMARKER = ++YYCURSOR);
		if(yych == 0x0A) goto yy71;
		if(yych == '^') goto yy108;
		goto yy107;
yy71:
#line 275 "scanner.re"
		{
					fatal("unterminated range (missing ])");
				}
#line 546 "scanner.cc"
yy72:
		yyaccept = 4;
		yych = *(YYMARKER = ++YYCURSOR);
		if(yych == '>') goto yy101;
		goto yy63;
yy73:
		yych = *++YYCURSOR;
		goto yy63;
yy74:
		++YYCURSOR;
#line 290 "scanner.re"
		{
					yylval.op = *tok;
					RETURN(CLOSE);
				}
#line 562 "scanner.cc"
yy76:
		++YYCURSOR;
		if((yych = *YYCURSOR) == 'e') goto yy93;
		goto yy92;
yy77:
#line 330 "scanner.re"
		{
					cur = cursor;
					yylval.symbol = Symbol::find(token());
					return ID;
				}
#line 574 "scanner.cc"
yy78:
		yych = *++YYCURSOR;
		goto yy92;
yy79:
		++YYCURSOR;
#line 336 "scanner.re"
		{
					cur = cursor;
					yylval.regexp = mkDot();
					return RANGE;
				}
#line 586 "scanner.cc"
yy81:
		++YYCURSOR;
		yych = *YYCURSOR;
		goto yy90;
yy82:
#line 342 "scanner.re"
		{
					goto scan;
				}
#line 596 "scanner.cc"
yy83:
		++YYCURSOR;
yy84:
#line 346 "scanner.re"
		{
					if(cursor == eof) RETURN(0);
					pos = cursor;
					cline++;
					goto scan;
				}
#line 607 "scanner.cc"
yy85:
		++YYCURSOR;
		if((yych = *YYCURSOR) == 0x0A) goto yy88;
yy86:
#line 353 "scanner.re"
		{
					std::ostringstream msg;
					msg << "unexpected character: ";
					prtChOrHex(msg, *tok);
					fatal(msg.str().c_str());
					goto scan;
				}
#line 620 "scanner.cc"
yy87:
		yych = *++YYCURSOR;
		goto yy86;
yy88:
		yych = *++YYCURSOR;
		goto yy84;
yy89:
		++YYCURSOR;
		if(YYLIMIT == YYCURSOR) YYFILL(1);
		yych = *YYCURSOR;
yy90:
		if(yybm[0+yych] & 2) {
			goto yy89;
		}
		goto yy82;
yy91:
		++YYCURSOR;
		if(YYLIMIT == YYCURSOR) YYFILL(1);
		yych = *YYCURSOR;
yy92:
		if(yybm[0+yych] & 4) {
			goto yy91;
		}
		goto yy77;
yy93:
		yych = *++YYCURSOR;
		if(yych != '2') goto yy92;
		yych = *++YYCURSOR;
		if(yych != 'c') goto yy92;
		yyaccept = 5;
		yych = *(YYMARKER = ++YYCURSOR);
		if(yych != ':') goto yy92;
yy96:
		++YYCURSOR;
		if(YYLIMIT == YYCURSOR) YYFILL(1);
		yych = *YYCURSOR;
		if(yych <= '^') {
			if(yych <= '@') goto yy97;
			if(yych <= 'Z') goto yy98;
		} else {
			if(yych == '`') goto yy97;
			if(yych <= 'z') goto yy98;
		}
yy97:
		YYCURSOR = YYMARKER;
		if(yyaccept <= 3) {
			if(yyaccept <= 1) {
				if(yyaccept <= 0) {
					goto yy61;
				} else {
					goto yy67;
				}
			} else {
				if(yyaccept <= 2) {
					goto yy69;
				} else {
					goto yy71;
				}
			}
		} else {
			if(yyaccept <= 5) {
				if(yyaccept <= 4) {
					goto yy63;
				} else {
					goto yy77;
				}
			} else {
				if(yyaccept <= 6) {
					goto yy100;
				} else {
					goto yy134;
				}
			}
		}
yy98:
		yyaccept = 6;
		YYMARKER = ++YYCURSOR;
		if(YYLIMIT == YYCURSOR) YYFILL(1);
		yych = *YYCURSOR;
		if(yych <= 'Z') {
			if(yych <= '9') {
				if(yych >= '0') goto yy98;
			} else {
				if(yych <= ':') goto yy96;
				if(yych >= 'A') goto yy98;
			}
		} else {
			if(yych <= '_') {
				if(yych >= '_') goto yy98;
			} else {
				if(yych <= '`') goto yy100;
				if(yych <= 'z') goto yy98;
			}
		}
yy100:
#line 322 "scanner.re"
		{
					cur = cursor;
					tok+= 5; /* skip "re2c:" */
					iscfg = 1;
					yylval.str = new Str(token());
					return CONFIG;
				}
#line 724 "scanner.cc"
yy101:
		YYCTXMARKER = YYCURSOR + 1;
		yych = *++YYCURSOR;
		goto yy103;
yy102:
		++YYCURSOR;
		if(YYLIMIT == YYCURSOR) YYFILL(1);
		yych = *YYCURSOR;
yy103:
		if(yybm[0+yych] & 8) {
			goto yy102;
		}
		if(yych != '{') goto yy97;
		++YYCURSOR;
		YYCURSOR = YYCTXMARKER;
#line 279 "scanner.re"
		{
					RETURN(NOCOND);
				}
#line 744 "scanner.cc"
yy106:
		++YYCURSOR;
		if(YYLIMIT == YYCURSOR) YYFILL(1);
		yych = *YYCURSOR;
yy107:
		if(yybm[0+yych] & 16) {
			goto yy106;
		}
		if(yych <= '[') goto yy97;
		if(yych <= '\\') goto yy110;
		goto yy111;
yy108:
		++YYCURSOR;
		if(YYLIMIT == YYCURSOR) YYFILL(1);
		yych = *YYCURSOR;
		if(yych <= '[') {
			if(yych == 0x0A) goto yy97;
			goto yy108;
		} else {
			if(yych <= '\\') goto yy113;
			if(yych <= ']') goto yy114;
			goto yy108;
		}
yy110:
		++YYCURSOR;
		if(YYLIMIT == YYCURSOR) YYFILL(1);
		yych = *YYCURSOR;
		if(yych == 0x0A) goto yy97;
		goto yy106;
yy111:
		++YYCURSOR;
#line 269 "scanner.re"
		{
					cur = cursor;
					yylval.regexp = ranToRE(token());
					return RANGE;
				}
#line 782 "scanner.cc"
yy113:
		++YYCURSOR;
		if(YYLIMIT == YYCURSOR) YYFILL(1);
		yych = *YYCURSOR;
		if(yych == 0x0A) goto yy97;
		goto yy108;
yy114:
		++YYCURSOR;
#line 263 "scanner.re"
		{
					cur = cursor;
					yylval.regexp = invToRE(token());
					return RANGE;
				}
#line 797 "scanner.cc"
yy116:
		++YYCURSOR;
		if(YYLIMIT == YYCURSOR) YYFILL(1);
		yych = *YYCURSOR;
yy117:
		if(yybm[0+yych] & 32) {
			goto yy116;
		}
		if(yych <= '&') goto yy97;
		if(yych <= '\'') goto yy119;
		++YYCURSOR;
		if(YYLIMIT == YYCURSOR) YYFILL(1);
		yych = *YYCURSOR;
		if(yych == 0x0A) goto yy97;
		goto yy116;
yy119:
		++YYCURSOR;
#line 250 "scanner.re"
		{
					cur = cursor;
					yylval.regexp = strToCaseInsensitiveRE(token());
					return STRING;
				}
#line 821 "scanner.cc"
yy121:
		++YYCURSOR;
		if(YYLIMIT == YYCURSOR) YYFILL(1);
		yych = *YYCURSOR;
yy122:
		if(yybm[0+yych] & 64) {
			goto yy121;
		}
		if(yych <= '!') goto yy97;
		if(yych <= '"') goto yy124;
		++YYCURSOR;
		if(YYLIMIT == YYCURSOR) YYFILL(1);
		yych = *YYCURSOR;
		if(yych == 0x0A) goto yy97;
		goto yy121;
yy124:
		++YYCURSOR;
#line 244 "scanner.re"
		{
					cur = cursor;
					yylval.regexp = strToRE(token());
					return STRING;
				}
#line 845 "scanner.cc"
yy126:
		++YYCURSOR;
#line 239 "scanner.re"
		{
					tok = cursor;
					RETURN(0);
				}
#line 853 "scanner.cc"
yy128:
		++YYCURSOR;
#line 234 "scanner.re"
		{
					depth = 1;
					goto comment;
				}
#line 861 "scanner.cc"
yy130:
		yych = *++YYCURSOR;
		if(yych == ',') goto yy144;
		goto yy132;
yy131:
		++YYCURSOR;
		if((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
		yych = *YYCURSOR;
yy132:
		if(yybm[0+yych] & 128) {
			goto yy131;
		}
		if(yych == ',') goto yy137;
		if(yych == '}') goto yy135;
		goto yy97;
yy133:
		++YYCURSOR;
yy134:
#line 318 "scanner.re"
		{
					fatal("illegal closure form, use '{n}', '{n,}', '{n,m}' where n and m are numbers");
				}
#line 884 "scanner.cc"
yy135:
		++YYCURSOR;
#line 300 "scanner.re"
		{
					yylval.extop.minsize = atoi((char *)tok+1);
					yylval.extop.maxsize = atoi((char *)tok+1);
					RETURN(CLOSESIZE);
				}
#line 893 "scanner.cc"
yy137:
		yyaccept = 7;
		yych = *(YYMARKER = ++YYCURSOR);
		if(yych <= '/') goto yy134;
		if(yych <= '9') goto yy140;
		if(yych != '}') goto yy134;
		++YYCURSOR;
#line 312 "scanner.re"
		{
					yylval.extop.minsize = atoi((char *)tok+1);
					yylval.extop.maxsize = -1;
					RETURN(CLOSESIZE);
				}
#line 907 "scanner.cc"
yy140:
		++YYCURSOR;
		if(YYLIMIT == YYCURSOR) YYFILL(1);
		yych = *YYCURSOR;
		if(yych <= '/') goto yy97;
		if(yych <= '9') goto yy140;
		if(yych != '}') goto yy97;
		++YYCURSOR;
#line 306 "scanner.re"
		{
					yylval.extop.minsize = atoi((char *)tok+1);
					yylval.extop.maxsize = MAX(yylval.extop.minsize,atoi(strchr((char *)tok, ',')+1));
					RETURN(CLOSESIZE);
				}
#line 922 "scanner.cc"
yy144:
		yyaccept = 7;
		yych = *(YYMARKER = ++YYCURSOR);
		if(yych <= '/') goto yy134;
		if(yych <= '9') goto yy140;
		if(yych != '}') goto yy134;
		++YYCURSOR;
#line 295 "scanner.re"
		{
					yylval.op = '*';
					RETURN(CLOSE);
				}
#line 935 "scanner.cc"
	}
}
#line 360 "scanner.re"


code:
{
	static const unsigned char yybm[] = {
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192,   0, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192,  64, 192, 192, 192, 192, 128, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192,   0, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
		192, 192, 192, 192, 192, 192, 192, 192, 
	};

#line 978 "scanner.cc"
	{
		YYCTYPE yych;
		if((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
		yych = *YYCURSOR;
		if(yych <= '&') {
			if(yych <= 0x0A) {
				if(yych <= 0x00) goto yy155;
				if(yych <= 0x09) goto yy157;
				goto yy153;
			} else {
				if(yych == '"') goto yy159;
				goto yy157;
			}
		} else {
			if(yych <= '{') {
				if(yych <= '\'') goto yy160;
				if(yych <= 'z') goto yy157;
				goto yy151;
			} else {
				if(yych != '}') goto yy157;
			}
		}
		++YYCURSOR;
#line 364 "scanner.re"
		{
					if(--depth == 0)
					{
						cur = cursor;
						yylval.token = new Token(token(), tline);
						return CODE;
					}
					goto code;
				}
#line 1012 "scanner.cc"
yy151:
		++YYCURSOR;
#line 373 "scanner.re"
		{
					++depth;
					goto code;
				}
#line 1020 "scanner.cc"
yy153:
		++YYCURSOR;
#line 377 "scanner.re"
		{
					if(cursor == eof)
					{
						fatal("missing '}'");
					}
					pos = cursor;
					cline++;
					goto code;
				}
#line 1033 "scanner.cc"
yy155:
		++YYCURSOR;
#line 386 "scanner.re"
		{
					if(cursor == eof)
					{
						if (depth)
						{
							fatal("missing '}'");
						}
						RETURN(0);
					}
					goto code;
				}
#line 1048 "scanner.cc"
yy157:
		++YYCURSOR;
yy158:
#line 397 "scanner.re"
		{
					goto code;
				}
#line 1056 "scanner.cc"
yy159:
		yych = *(YYMARKER = ++YYCURSOR);
		if(yych == 0x0A) goto yy158;
		goto yy166;
yy160:
		yych = *(YYMARKER = ++YYCURSOR);
		if(yych == 0x0A) goto yy158;
		goto yy162;
yy161:
		++YYCURSOR;
		if(YYLIMIT == YYCURSOR) YYFILL(1);
		yych = *YYCURSOR;
yy162:
		if(yybm[0+yych] & 64) {
			goto yy161;
		}
		if(yych <= '&') goto yy163;
		if(yych <= '\'') goto yy157;
		goto yy164;
yy163:
		YYCURSOR = YYMARKER;
		goto yy158;
yy164:
		++YYCURSOR;
		if(YYLIMIT == YYCURSOR) YYFILL(1);
		yych = *YYCURSOR;
		if(yych == 0x0A) goto yy163;
		goto yy161;
yy165:
		++YYCURSOR;
		if(YYLIMIT == YYCURSOR) YYFILL(1);
		yych = *YYCURSOR;
yy166:
		if(yybm[0+yych] & 128) {
			goto yy165;
		}
		if(yych <= '!') goto yy163;
		if(yych <= '"') goto yy157;
		++YYCURSOR;
		if(YYLIMIT == YYCURSOR) YYFILL(1);
		yych = *YYCURSOR;
		if(yych == 0x0A) goto yy163;
		goto yy165;
	}
}
#line 400 "scanner.re"


comment:
{

#line 1108 "scanner.cc"
	{
		YYCTYPE yych;
		if((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
		yych = *YYCURSOR;
		if(yych <= ')') {
			if(yych == 0x0A) goto yy173;
			goto yy175;
		} else {
			if(yych <= '*') goto yy170;
			if(yych == '/') goto yy172;
			goto yy175;
		}
yy170:
		++YYCURSOR;
		if((yych = *YYCURSOR) == '/') goto yy178;
yy171:
#line 428 "scanner.re"
		{
					if(cursor == eof)
					{
						RETURN(0);
					}
					goto comment;
				}
#line 1133 "scanner.cc"
yy172:
		yych = *++YYCURSOR;
		if(yych == '*') goto yy176;
		goto yy171;
yy173:
		++YYCURSOR;
#line 419 "scanner.re"
		{
					if(cursor == eof)
					{
						RETURN(0);
					}
					tok = pos = cursor;
					cline++;
					goto comment;
				}
#line 1150 "scanner.cc"
yy175:
		yych = *++YYCURSOR;
		goto yy171;
yy176:
		++YYCURSOR;
#line 414 "scanner.re"
		{
					++depth;
					fatal("ambiguous /* found");
					goto comment;
				}
#line 1162 "scanner.cc"
yy178:
		++YYCURSOR;
#line 404 "scanner.re"
		{
					if(--depth == 0)
					{
						goto scan;
					}
					else
					{
						goto comment;
					}
				}
#line 1176 "scanner.cc"
	}
}
#line 435 "scanner.re"


config:
{
	static const unsigned char yybm[] = {
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0, 128,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		128,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
	};

#line 1219 "scanner.cc"
	{
		YYCTYPE yych;
		if((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
		yych = *YYCURSOR;
		if(yych <= 0x1F) {
			if(yych != 0x09) goto yy186;
		} else {
			if(yych <= ' ') goto yy182;
			if(yych == '=') goto yy184;
			goto yy186;
		}
yy182:
		++YYCURSOR;
		yych = *YYCURSOR;
		goto yy191;
yy183:
#line 439 "scanner.re"
		{
					goto config;
				}
#line 1240 "scanner.cc"
yy184:
		++YYCURSOR;
		yych = *YYCURSOR;
		goto yy189;
yy185:
#line 442 "scanner.re"
		{
					iscfg = 2;
					cur = cursor;
					RETURN('=');
				}
#line 1252 "scanner.cc"
yy186:
		++YYCURSOR;
#line 447 "scanner.re"
		{
					fatal("missing '='");
				}
#line 1259 "scanner.cc"
yy188:
		++YYCURSOR;
		if(YYLIMIT == YYCURSOR) YYFILL(1);
		yych = *YYCURSOR;
yy189:
		if(yybm[0+yych] & 128) {
			goto yy188;
		}
		goto yy185;
yy190:
		++YYCURSOR;
		if(YYLIMIT == YYCURSOR) YYFILL(1);
		yych = *YYCURSOR;
yy191:
		if(yych == 0x09) goto yy190;
		if(yych == ' ') goto yy190;
		goto yy183;
	}
}
#line 450 "scanner.re"


value:
{
	static const unsigned char yybm[] = {
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 192,   0, 248, 248, 192, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		192, 248, 104, 248, 248, 248, 248, 152, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		252, 252, 252, 252, 252, 252, 252, 252, 
		252, 252, 248, 192, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248,   8, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
		248, 248, 248, 248, 248, 248, 248, 248, 
	};

#line 1319 "scanner.cc"
	{
		YYCTYPE yych;
		if((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
		yych = *YYCURSOR;
		if(yych <= '&') {
			if(yych <= 0x0D) {
				if(yych <= 0x08) goto yy200;
				if(yych <= 0x0A) goto yy194;
				if(yych <= 0x0C) goto yy200;
			} else {
				if(yych <= ' ') {
					if(yych <= 0x1F) goto yy200;
				} else {
					if(yych == '"') goto yy202;
					goto yy200;
				}
			}
		} else {
			if(yych <= '/') {
				if(yych <= '\'') goto yy204;
				if(yych == '-') goto yy197;
				goto yy200;
			} else {
				if(yych <= '9') {
					if(yych <= '0') goto yy195;
					goto yy198;
				} else {
					if(yych != ';') goto yy200;
				}
			}
		}
yy194:
#line 460 "scanner.re"
		{
					cur = cursor;
					yylval.str = new Str(token());
					iscfg = 0;
					return VALUE;
				}
#line 1359 "scanner.cc"
yy195:
		++YYCURSOR;
		if(yybm[0+(yych = *YYCURSOR)] & 8) {
			goto yy200;
		}
yy196:
#line 454 "scanner.re"
		{
					cur = cursor;
					yylval.number = atoi(token().to_string().c_str());
					iscfg = 0;
					return NUMBER;
				}
#line 1373 "scanner.cc"
yy197:
		yych = *++YYCURSOR;
		if(yych <= '0') goto yy201;
		if(yych >= ':') goto yy201;
yy198:
		++YYCURSOR;
		if(YYLIMIT == YYCURSOR) YYFILL(1);
		yych = *YYCURSOR;
		if(yybm[0+yych] & 4) {
			goto yy198;
		}
		if(yych <= 0x0D) {
			if(yych <= 0x08) goto yy200;
			if(yych <= 0x0A) goto yy196;
			if(yych >= 0x0D) goto yy196;
		} else {
			if(yych <= ' ') {
				if(yych >= ' ') goto yy196;
			} else {
				if(yych == ';') goto yy196;
			}
		}
yy200:
		++YYCURSOR;
		if(YYLIMIT == YYCURSOR) YYFILL(1);
		yych = *YYCURSOR;
yy201:
		if(yybm[0+yych] & 8) {
			goto yy200;
		}
		goto yy194;
yy202:
		YYMARKER = ++YYCURSOR;
		if(YYLIMIT == YYCURSOR) YYFILL(1);
		yych = *YYCURSOR;
		if(yybm[0+yych] & 16) {
			goto yy202;
		}
		if(yych <= '!') {
			if(yych == 0x0A) goto yy194;
			goto yy212;
		} else {
			if(yych <= '"') goto yy200;
			if(yych <= '[') goto yy212;
			goto yy214;
		}
yy204:
		YYMARKER = ++YYCURSOR;
		if(YYLIMIT == YYCURSOR) YYFILL(1);
		yych = *YYCURSOR;
		if(yybm[0+yych] & 32) {
			goto yy204;
		}
		if(yych <= '&') {
			if(yych == 0x0A) goto yy194;
		} else {
			if(yych <= '\'') goto yy200;
			if(yych >= '\\') goto yy209;
		}
yy206:
		++YYCURSOR;
		if(YYLIMIT == YYCURSOR) YYFILL(1);
		yych = *YYCURSOR;
		if(yybm[0+yych] & 64) {
			goto yy206;
		}
		if(yych <= '&') goto yy208;
		if(yych <= '\'') goto yy210;
		goto yy211;
yy208:
		YYCURSOR = YYMARKER;
		goto yy194;
yy209:
		YYMARKER = ++YYCURSOR;
		if(YYLIMIT == YYCURSOR) YYFILL(1);
		yych = *YYCURSOR;
		if(yych <= 0x0D) {
			if(yych <= 0x09) {
				if(yych <= 0x08) goto yy204;
				goto yy206;
			} else {
				if(yych <= 0x0A) goto yy194;
				if(yych <= 0x0C) goto yy204;
				goto yy206;
			}
		} else {
			if(yych <= ' ') {
				if(yych <= 0x1F) goto yy204;
				goto yy206;
			} else {
				if(yych == ';') goto yy206;
				goto yy204;
			}
		}
yy210:
		yych = *++YYCURSOR;
		goto yy194;
yy211:
		++YYCURSOR;
		if(YYLIMIT == YYCURSOR) YYFILL(1);
		yych = *YYCURSOR;
		if(yych == 0x0A) goto yy208;
		goto yy206;
yy212:
		++YYCURSOR;
		if(YYLIMIT == YYCURSOR) YYFILL(1);
		yych = *YYCURSOR;
		if(yybm[0+yych] & 128) {
			goto yy212;
		}
		if(yych <= '!') goto yy208;
		if(yych <= '"') goto yy210;
		goto yy215;
yy214:
		YYMARKER = ++YYCURSOR;
		if(YYLIMIT == YYCURSOR) YYFILL(1);
		yych = *YYCURSOR;
		if(yych <= 0x0D) {
			if(yych <= 0x09) {
				if(yych <= 0x08) goto yy202;
				goto yy212;
			} else {
				if(yych <= 0x0A) goto yy194;
				if(yych <= 0x0C) goto yy202;
				goto yy212;
			}
		} else {
			if(yych <= ' ') {
				if(yych <= 0x1F) goto yy202;
				goto yy212;
			} else {
				if(yych == ';') goto yy212;
				goto yy202;
			}
		}
yy215:
		++YYCURSOR;
		if(YYLIMIT == YYCURSOR) YYFILL(1);
		yych = *YYCURSOR;
		if(yych == 0x0A) goto yy208;
		goto yy212;
	}
}
#line 466 "scanner.re"

}

void Scanner::fatal(uint ofs, const char *msg) const
{
	out.flush();
	std::cerr << "re2c: error: "
		<< "line " << tline << ", column " << (tchar + ofs + 1) << ": "
		<< msg << std::endl;
	exit(1);
}

Scanner::~Scanner()
{
	if (bot)
	{
		delete [] bot;
	}
}

} // end namespace re2c

/*
  Stockfish, a UCI chess playing engine derived from Glaurung 2.1
  Copyright (C) 2004-2008 Tord Romstad (Glaurung author)
  Copyright (C) 2008-2015 Marco Costalba, Joona Kiiski, Tord Romstad
  Copyright (C) 2015-2016 Marco Costalba, Joona Kiiski, Gary Linscott, Tord Romstad

  Stockfish is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Stockfish is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef UCI_H
#define UCI_H

#include <string.h>

#include "types.h"

struct Option;
typedef struct Option Option;

typedef void (*OnChange)(Option *);

enum {
  OPT_TYPE_CHECK, OPT_TYPE_SPIN, OPT_TYPE_DISABLED
};

enum {
  OPT_THREADS,
  OPT_HASH,
  OPT_PONDER,
  OPT_CHESS960,
  OPT_LARGE_PAGES,
};

struct Option {
  char *name;
  int type;
  int def, minVal, maxVal;
  char *defString;
  OnChange onChange;
  int value;
  char *valString;
};

void options_init(void);
void print_options(void);
int option_value(int opt);
const char *option_string_value(int opt);
const char *option_default_string_value(int opt);
void option_set_value(int opt, int value);
bool option_set_by_name(char *name, char *value);

void setoption(char *str);
void position(Position *pos, char *str);

void uci_loop(int argc, char* argv[]);
char *uci_value(char *str, Value v);
char *uci_square(char *str, Square s);
char *uci_move(char *str, Move m, int chess960);
void print_pv(Position *pos, Depth depth, Value alpha, Value beta);
Move uci_to_move(const Position *pos, char *str);

#endif

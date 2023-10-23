#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

/**
 * enum kind_e - func.
 * @SPADE: arg one.
 * @HEART: arg two.
 * @CLUB: arg three..
 * @DIAMOND: arg foure.
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - obj
 *
 * @value: arg one.
 * @kind: arg two.
 */

typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - obj
 *
 * @card: arg one
 * @prev: arg two
 * @next: arg three
 */

typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif

#include "include/queue.h"
#include <stdlib.h>
#include <stdio.h>

struct queue *queue_init(void)
{
    struct queue *q = calloc(1, sizeof(struct queue));
    if (!q)
        return NULL;
    return q;
}

size_t queue_size(struct queue *q)
{
    return q->size;
}

int queue_push(struct queue *q, struct token *elm)
{
    struct list *last = malloc(sizeof(struct list));
    last->next = NULL;
    last->elm = elm;
    if (!q->tail)
    {
        q->head = last;
        q->tail = last;
    }
    else
    {
        q->tail->next = last;
        q->tail = last;
    }
    q->size++;
    return 1;
}

struct token *queue_peek(struct queue *q)
{
    if (!q->head)
	return NULL;
    return q->head->elm;
}

struct token *queue_pop(struct queue *q)
{
    if (!q->head)
        return NULL;
    else
    {
        struct token *tmp = q->head->elm;
        struct list *tmp2 = q->head;
        q->head = q->head->next;
        free(tmp2);
        q->size = q->size - 1;
        return tmp;
    }
}

void queue_destroy(struct queue *q)
{
    while (q->size != 0)
    {
        struct token *tmp = queue_pop(q);
        free(tmp);
    }
    free(q);
}

void queue_print(struct queue *q)
{
    if (!q->head)
        return;
    else
    {
        size_t i = 0;
        struct list *tmp = q->head;
        while (i < q->size)
        {
            token_print(tmp->elm);
            if (i < q->size - 1)
                printf(" -> ");
            tmp = tmp->next;
            i++;
        }
	printf("\n");
        return;
    }
}





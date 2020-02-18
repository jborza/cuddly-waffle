#pragma once
#include "TodoItem.h"

typedef struct TodoListNode {
	struct TodoItem current;
	struct TodoListNode *next;
} TodoListNode;
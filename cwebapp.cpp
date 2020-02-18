#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TodoList.h"

void* mallocz(size_t size) {
	void* ptr = malloc(size);
	if (ptr)
		memset(ptr, 0, size);
	return ptr;
}

TodoListNode* createNode(const char* title) {
	TodoListNode *node = (TodoListNode*)mallocz(sizeof(TodoListNode));
	strncpy_s(node->current.title, title, TITLE_MAXLENGTH);
	return node;
}

TodoListNode* createList() {
	TodoListNode* head = createNode("Read a C tutorial online");
	head->current.done = 1;
	head->next = createNode("Read about HTML");
	head->next->next = createNode("Write a web framework");
	head->next->next->next = createNode("Profit");
	return head;
}

int main()
{
	printf("Todo list\n");
	TodoListNode* todoList = createList();
	do {
		printf("%s: %s\n", todoList->current.title, todoList->current.done ? "[x]" : "[ ]");
	} while ((todoList = todoList->next) != NULL);
}
#pragma once
const int TODOITEM_TITLE_MAXLENGTH = 256;
typedef struct TodoItem {
	char title[TODOITEM_TITLE_MAXLENGTH];
	int done; //0 = not done
} TodoItem;
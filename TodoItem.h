#pragma once
const int TITLE_MAXLENGTH = 256;
typedef struct TodoItem {
	char title[TITLE_MAXLENGTH];
	int done; //0 = not done
} TodoItem;
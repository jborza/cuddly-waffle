#include "TodoItem.h"
#include <string.h>

typedef void Item;

typedef struct TodoItemView {
	Item* container;
	Item* checkbox;
	Item* label;
	Item* editBox;
	Item* saveButton;
	int editing = 0;
} TodoItemView;

#define true 1
#define false 0

//TODO definitions!

void add_child(Item* container, Item* child);

Item* create_element(const char* tag);

void invalidate();

char* get_attribute(Item* item, const char* attribute);

void set_attribute(Item* item, const char* attribute, const char* value);

void set_body(Item* item, const char* body);

void set_element_visible(Item* item, int visible);

void add_click_handler(Item* item, void* handler);


void saveButton_click(TodoItem* model, TodoItemView *state) {
	strcpy_s(model->title, TODOITEM_TITLE_MAXLENGTH, get_attribute(state->editBox, "value"));
	invalidate();
}

void checkbox_changed(TodoItem* model, TodoItemView* state) {
	strcpy_s(model->title, get_attribute(state->checkbox, "checked"));
	invalidate();
}

void layout(TodoItemView *state) {
	state->container = create_element("div");
	state->checkbox = create_element("input");
	set_attribute(state->checkbox, "type", "checkbox");
	add_child(state->container, state->checkbox);
	
	//display mode
	state->label = create_element("span");
	add_child(state->container, state->label);

	//edit mode
	state->saveButton = create_element("input");
	set_attribute(state->saveButton, "value", "Save");
	add_click_handler(state->saveButton, &saveButton_click);
	add_child(state->container, state->saveButton);

	state->editBox = create_element("input");
	set_attribute(state->editBox, "placeholder", "What do you want to do?");
	add_child(state->container, state->editBox);
}

void render(TodoItemView *state, TodoItem *model) {
	set_attribute(state->checkbox, "checked", model->done ? "checked" : "");
	if (state->editing)
		set_body(state->editBox, model->title);
	else
		set_body(state->label, model->title);

	//visibility
	set_element_visible(state->editBox, state->editing);
	set_element_visible(state->saveButton, state->editing);
	set_element_visible(state->label, !state->editing);
}
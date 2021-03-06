#ifndef _MENU_H
#define _MENU_H

// characters for special entries
#define MENU_DEFAULT	'd'
#define MENU_REBOOT		'r'
#define MENU_HALT			's'
#define MENU_RECOVERY	'R'
#define MENU_SHELL		'#'
/* our functions return integers
 * i known that a char it's an int value,
 * but user can have an entry ID which have the same value of a char.
 * so i decided to use negative numbers for special entries.
 */
#define MENU_DEFAULT_NUM 	-1
#define MENU_REBOOT_NUM		-2
#define MENU_HALT_NUM 		-3
#define MENU_RECOVERY_NUM	-4
#define MENU_SHELL_NUM		-5

// percentage of screen used by the menu
#define MENU_WIDTH_PERC 50


typedef struct _menu_entry
{
	unsigned int id;
	char 	*name,
				*blkdev,
				*kernel,
				*cmdline,
				*initrd;
	struct _menu_entry *next;
} menu_entry;

void free_entry(menu_entry *);
void free_menu(menu_entry *);
void print_menu(menu_entry *);
void clear_screen(void);
menu_entry *add_entry(menu_entry *, char *, char *,char *, char *, char *);
menu_entry *del_entry(menu_entry *, menu_entry *);
menu_entry *get_item_by_id(menu_entry *, int);
#endif
# liblist
A simple library with a bunch of functions to work with linked lists (man page included in `man` folder)
I didn't write all man pages yet, but you can find the global man page in `man` folder.
For free functions use `NO_FREE` macro when you just want to clear the list but not free it's data (`FREE_2` and `FREE_3` for two/three dimensional lists), otherwise use `FREE_DFLT` (or `FREE_2_DATA`, `FREE_3_DATA`).
For dup functions (`lst_dup`, `lst_dup_from`, `lst_ndup`, `lst_ndup_from`), use `SHARE_DATA` (or `DUP_2_SHARE`, `DUP_3_SHARE`) if you don't want to duplicate the data (the duplicate data will just point to the original data), otherwise use `DUP_STRING` (or `DUP_2_STRING`, `DUP_3_STRING`) if you want to duplicate the data which is a string (char*) with `strdup`.
If the data is not a string and you want to duplicate it, you can use your own duplicate function, which is prototyped as `void * dup_f(const void *)`.

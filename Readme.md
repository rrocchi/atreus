# Atreus keyboard dvorak layout

This is the **dvorak** layout that I use on my [atreus](https://atreus.technomancy.us/) keyboards.


The difference with the standard atreus dvorak layout is the presence of the Alt-gr key
(Right-Alt) and some extra keys (notably multimedia) on L2.

It will work on Linux machines where Xorg is set to use the Option "XkbLayout" "us" with the Option "XkbVariant" "altgr-intl".

To install it, copy the file keymap_dvorak_rook.c in
https://github.com/technomancy/tmk_keyboard/tree/atreus/keyboard/atreus and
compile with

> $ make upload KEYMAP=dvorak_rook USB=/dev/ttyACM0


Hex Key's Code Finder 
for BeOS

Version 1.2

Writted by Mattia Tristo <mattia_tristo@libero.it>

------------------------------------------------------------
        Version developed under Zeta operating system
----------------------------------------------------------------------


Hex Key Code Finder is a program writted to make easy the creation of
a new keymap or the personalization of an existing one.
This utility allow the user to research, by pressing a key, the
exadecimal code of this one, the code will be utilized to modify and
to personalize the keymap.
Pressing the mouse over a key in the table of the main window, makes a
new window appear, with the information of the caracters mapped to
that key, it is possible to change this values pressing the
corresponding "Modify" button and selecting a new value from a table
of UTF-8 characters. Pressing the button "Modify" in the last window
applies the changes.
Also, if you want to procede manually, you can obtain a starting base
of a keymap, just opening a terminal and writing this command :
"keymap - d >> filename_of_your_choice", then, using Hex key's Code
Finder, it will be possible to find the hexadecimal value of the key
to be mapped, once obtained this value, just open the keymap's file,
search for this value, fill in the nine fields with the wanted
characters for the nine maps corresponding to the simultaneously
pression of modifier keys or not and then save the file.
After that, to make active the changes, open the terminal and write
the command "keymap - l << filename".

This software is distibuited under the BSD PUBLIC LICENSE,
see the file LICENSE for more details.

                      Padova - Italy - 09/02/2006

                          Mattia aka Yappi
                       mattia_tristo@libero.it

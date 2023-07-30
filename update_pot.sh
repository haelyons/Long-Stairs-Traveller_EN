#!/bin/bash

# Update .POT file with any new or removed marked strings (see gettext initialisation in main.cpp)
find . -iname "*.*pp" | xargs xgettext --from-code=UTF-8 --keyword="_" --output="locales/lst.pot"

# Merge the updated .POT file with the current .POT file for the selected translation
# After this you'll need to edit the .PO files with the translations
msgmerge "locales/en_US.UTF-8/lst-en.po" "locales/lst.pot" --output-file="locales/en_US.UTF-8/lst-en.po"

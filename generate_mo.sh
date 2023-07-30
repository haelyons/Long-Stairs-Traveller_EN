!/bin/bash

# Generate new .MO file from the current .PO file
msgfmt "locales/en_US.UTF-8/lst-en.po" --output-file="locales/en_US.UTF-8/LC_MESSAGES/lst-en.mo"
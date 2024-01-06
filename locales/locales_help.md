## i18n workflow readme 
### Terms
locales -> folder specified in the bindtextdomain
lst-en -> the current locales
LC_MESSAGES -> the category name of the translation 
lst-en.mo -> binary message catalog containing all the translations. The filename is specified in the bindtext domain
and text domain. 

### Basic steps
- We run xgettext on our files (main.cpp, etc) specifiying our keyword "_" with the output of a .pot file
- The .pot file contains a catalog of strings prefixed by our keyword, with a key value pair for the original string msgid
and the translation msgstr 
- We can now make the .po (portable object) file using the msginit tool. Every language will have its own .po file, 
which we can edit with the new translations using Poedit (or equivalent tools such as KBabel)
- With the translated .po file, we us msgfmt to create the final output (binary message catalog) which is loaded at runtime

These steps work well for the initial setup phase. Whenever the code changes we need to run:
1. xgettext again to get a new .pot file
2. msgmerge to merge this with our existing .po file to avoid overwriting our previous content, but include new content in the .mo
3. when the .po has the translated new strings, make a new internationalised .mo to be loaded at runtime

.PHONY : thesis

.PHONY : table

.PHONY : figure

.PHONY : layout

.PHONY : cover

.PHONY : correction

.PHONY : clean

.PHONY : all

thesis :
	latexmk -f -silent thesis.tex >/dev/null

correction :
	latexmk -f -silent correction.tex >/dev/null

table :
	latexmk -f -silent table.tex >/dev/null

figure :
	latexmk -f -silent figure.tex >/dev/null

layout :
	latexmk -f -silent layout.tex >/dev/null

cover :
	latexmk -f -silent cover.tex >/dev/null

all : thesis table figure layout cover

clean :
	latexmk -c
	rm -f *busy*
	rm -f chap/*.aux
	rm -rf .minted-*

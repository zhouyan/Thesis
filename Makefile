.PHONY : thesis

thesis :
	latexmk -f -silent thesis.tex

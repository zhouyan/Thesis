.PHONY : thesis

thesis :
	latexmk -f -silent thesis.tex >/dev/null

table :
	latexmk -f -silent table.tex >/dev/null

figure :
	latexmk -f -silent figure.tex >/dev/null

clean :
	latexmk -c
	rm -f *busy*
	rm -f chap/*.aux
	rm -rf .minted-*

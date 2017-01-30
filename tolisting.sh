echo '\\begin{verbatim}' > $2
cat -n $1 >> $2
echo '\\end{verbatim}' >> $2

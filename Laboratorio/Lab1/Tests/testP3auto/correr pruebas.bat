@echo off
echo Creando archivos de salida
echo --------------------------

echo ***** test1 *****
lab1 < test1.in > test1.sal
echo OK

echo ***** test2 *****
lab1 < test2.in > test2.sal
echo OK

echo ***** test3 *****
lab1 < test3.in > test3.sal
echo OK

echo ***** test4 *****
lab1 < test4.in > test4.sal
echo OK

echo --------------------------------------------------
echo - Ya estan creados los archivos de salida,       -
echo - ahora vamos a compararlos con los originales.  -
echo - Si esta todo bien el no tiene que decir nada   -
echo - abajo del nombre del archivo, si dice algo hay -
echo - alguna diferencia entre los archivos.          -
echo - Para comparar archivos yo uso el WinMerge.     -
echo --------------------------------------------------
pause

echo ***** test1 *****
diff test1.out test1.sal

echo ***** test2 *****
diff test2.out test2.sal

echo ***** test3 *****
diff test3.out test3.sal

echo ***** test4 *****
diff test4.out test4.sal

echo ***** dicc'sLlenos-Exprs *****
diff dicc'sLlenos-Exprs-Original.txt dicc'sLlenos-Exprs.txt

echo ***** dicc'sLlenos-Vars *****
diff dicc'sLlenos-Vars-Original.txt dicc'sLlenos-Vars.txt

echo ***** diccVarLleno-Exprs *****
diff diccVarLleno-Exprs-Original.txt diccVarLleno-Exprs.txt

echo ***** diccVarLleno-Vars *****
diff diccVarLleno-Vars-Original.txt diccVarLleno-Vars.txt

echo ***** soloexpr-Exprs *****
diff soloexpr-Exprs-Original.txt soloexpr-Exprs.txt

echo ***** soloexpr-Vars *****
diff soloexpr-Vars-Original.txt soloexpr-Vars.txt

echo ***** soloVariables-Exprs *****
diff soloVariables-Exprs-Original.txt soloVariables-Exprs.txt

echo ***** soloVariables-Vars *****
diff soloVariables-Vars-Original.txt soloVariables-Vars.txt

echo ***** vacio-Exprs *****
diff vacio-Exprs-Original.txt vacio-Exprs.txt

echo ***** vacio-Vars *****
diff vacio-Vars-Original.txt vacio-Vars.txt

echo ***** varyexpr-Exprs *****
diff varyexpr-Exprs-Original.txt varyexpr-Exprs.txt

echo ***** varyexpr-Vars *****
diff varyexpr-Vars-Original.txt varyexpr-Vars.txt

echo FIN
pause
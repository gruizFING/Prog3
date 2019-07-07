set path=%path%;c:\mingw;c:\mingw\bin;c:\mingw\include;c:\mingw\lib;c:\msys\1.0\bin;c:\mingw\mingw\bin

@echo ****************************************
@echo *             Compilando               *
@echo ****************************************

g++ -Wall -Werror -O1 -c ColaSimple.cpp
g++ -Wall -Werror -O1 -c ListaSimpleConPrioridad.cpp
g++ -Wall -Werror -O1 -c RedInfelicidad.cpp
g++ -Wall -Werror -O1 -c CarinioEstrategia.cpp
g++ -Wall -Werror -O1 -c util.cpp
g++ -Wall -Werror -O1 -c ListaCariniosos.cpp
g++ -Wall -Werror -O1 -c Test4.cpp
g++ -Wall -Werror -O1 -c Test5.cpp
g++ -Wall -Werror -O1 -c Test6.cpp
g++ -Wall -Werror -O1 -c Test10.cpp
g++ -Wall -Werror -O1 -c Prueba0.cpp
g++ -Wall -Werror -O1 -c Prueba1.cpp
g++ -Wall -Werror -O1 -c Prueba2.cpp
g++ -Wall -Werror -O1 -c Prueba3.cpp
g++ -Wall -Werror -O1 -c Prueba4.cpp

@echo ****************************************
@echo *                OK!                   *
@echo ****************************************

pause

@echo ****************************************
@echo *            Linkeditando              *
@echo ****************************************

g++ ColaSimple.o ListaSimpleConPrioridad.o RedInfelicidad.o CarinioEstrategia.o util.o ListaCariniosos.o Test4.o -o Test4.exe
g++ ColaSimple.o ListaSimpleConPrioridad.o RedInfelicidad.o CarinioEstrategia.o util.o ListaCariniosos.o Test5.o -o Test5.exe
g++ ColaSimple.o ListaSimpleConPrioridad.o RedInfelicidad.o CarinioEstrategia.o util.o ListaCariniosos.o Test6.o -o Test6.exe
g++ ColaSimple.o ListaSimpleConPrioridad.o RedInfelicidad.o CarinioEstrategia.o util.o ListaCariniosos.o Test10.o -o Test10.exe
g++ ColaSimple.o ListaSimpleConPrioridad.o RedInfelicidad.o CarinioEstrategia.o util.o ListaCariniosos.o Prueba0.o -o Prueba0.exe
g++ ColaSimple.o ListaSimpleConPrioridad.o RedInfelicidad.o CarinioEstrategia.o Prueba1.o -o Prueba1.exe
g++ ColaSimple.o ListaSimpleConPrioridad.o RedInfelicidad.o CarinioEstrategia.o Prueba2.o -o Prueba2.exe
g++ ColaSimple.o ListaSimpleConPrioridad.o RedInfelicidad.o CarinioEstrategia.o util.o ListaCariniosos.o Prueba3.o -o Prueba3.exe
g++ ColaSimple.o ListaSimpleConPrioridad.o RedInfelicidad.o CarinioEstrategia.o util.o ListaCariniosos.o Prueba4.o -o Prueba4.exe

@echo ****************************************
@echo *                OK!                   *
@echo ****************************************

pause

@echo ****************************************
@echo *      Creando archivos de salida      *
@echo ****************************************

Test4 > Test4.out
Test5 > Test5.out
Test6 > Test6.out
Test10 > Test10.out
Prueba0 > Prueba0.sal
Prueba1 > Prueba1.out
Prueba2 > Prueba2.out
Prueba3 > Prueba3.sal
@echo ****************************************
@echo *           puede demorar...         *
@echo ****************************************
Prueba4 > Prueba4.sal

@echo ****************************************
@echo *                OK!                   *
@echo ****************************************

pause

@echo ****************************************
@echo *    Comparando archivos de salida     *
@echo ****************************************

diff salidaTest4 Test4.out
diff salidaTest5 Test5.out
diff salidaTest6 Test6.out
diff salidaTest10 Test10.out
diff Prueba0.sal Prueba0.out
diff Prueba1.sal Prueba1.out
diff Prueba2.sal Prueba2.out
diff Prueba3.sal Prueba3.out

@echo ****************************************
@echo *                OK!                   *
@echo ****************************************

pause
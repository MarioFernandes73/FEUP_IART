# FEUP_IART

Repository for the course "Inteligência Artificial" (EIC0029) of the second semester of the third year of MIEIC in FEUP.

In this repository there is the practical assignment of this course in the lective year of 2016/2017.

The aim of this course is to:

  * Know what characterizes and distinguishes the artificial inteligence from its applicability.
  * Know how to represent, acquire, manipulate and apply knowledge using computating systems.
  * Develop a project using artificial intelligence techinques.
  
This project falls on the methods of problems resolutions theme and its aim is to develop an optimization algorithm to schedule an examp epoch. In order to do this, a genetic algorithm had to be made aswel as a simmulated annealing algorithm in order to compare the efficiency and results of both algorithms. The program also supports communication with local databases to get premade examples of hundreds of studends and dozens of courses and has an interface made with Qt.

 ** OFFICIAL PORTUGUESE DESCRIPTION **

Na Universidade da Porta a marcação de exames é feita de forma cuidadosa, tentando ao máximo facilitar a vida aos estudantes. Assim, antes da época de exames é recolhida informação sobre os estudantes inscritos em cada exame (época normal + época de recurso) de cada unidade curricular. É feita depois a calendarização dos exames, tentando evitar que haja estudantes inscritos em exames que terão lugar em dias consecutivos. Adicionalmente, pretende-se maximizar a distância entre exames sempre que haja estudantes em comum, embora sempre dentro da época de exames respetiva.

Uma solução será tanto melhor quando mais espaçados estiverem os exames dos estudantes. Contudo, deve ser tido em conta se os exames são do mesmo ano curricular, dando primazia a estudantes sem unidades curriculares em atraso -- um estudante com dois exames muito próximos correspondentes a duas unidades curriculares do mesmo ano sai mais penalizado do que se esses exames disserem respeito a unidades curriculares de anos diferentes.

O trabalho consiste em aplicar metodologias de otimização (Algoritmos Genéticos, Arrefecimento Simulado, ...) a este cenário, resolvendo instâncias de dimensões consideráveis: centenas de estudantes, dezenas de unidades curriculares, etc. Deve ser possível visualizar o mapa de exames de um estudante específico, bem como o mapa global de exames.


Database helping sites:

https://www.tutorialspoint.com/sqlite/sqlite_c_cpp.htm
http://www.dreamincode.net/forums/topic/122300-sqlite-in-c/

Making a class schedule using a genetic algorithm:

https://www.codeproject.com/Articles/23111/Making-a-Class-Schedule-Using-a-Genetic-Algorithm

Credits:
* [Mário Fernandes](https://github.com/MarioFernandes73)
* [Inês Gomes](https://github.com/inesgomes)
* [Catarina Ramos](https://github.com/catramos96)

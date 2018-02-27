---
title:
- Learn Vim
subtitle:
- ~~Glorified Vimtutor~~
author:
- Ricardo Vela
date:
- martes 27 de febrero, 2018
theme:
- Hannover
colortheme:
- cormorant
header-includes:
- \usepackage{subcaption}
- \usepackage{listings}
---


# Su... *servidor*

\begin{figure}[t!]
    \centering
    \begin{subfigure}[t]{0.5\textwidth}
        \centering
        \includegraphics[height=1.8in]{Niyx2.jpg}
    \end{subfigure}%
    ~ 
    \begin{subfigure}[t]{0.5\textwidth}
        \centering
        \includegraphics[height=1.8in]{baiabaia.jpg}
    \end{subfigure}
\end{figure}

+ ITC de cuarto semestre
+ Pseudo Perl Monger (gotta **grepresent**)
+ Comegalletas
+ Definitivamente no una autoridad para dar esta plática
+ (y hago prácticas en NIC México)

# ¿Qué saben de Vim?
\begin{figure}[h]
\centering
\includegraphics[height=2in]{vimlogo.png}
\end{figure}
+ ¿Qué han escuchado de Vim?
+ ¿Lo han usado?

# Temas
## Veremos..
- Instalación
- Cómo entrar
- Cómo salir
- Cómo salir
- Lidiar con la frustración de no poder salir
- Cómo salir (reprise)

# Temas
\small

+ ¿Qué distingue a Vim? ¿Por qué Vim?
+ Instalación
+ Los modos 
    - Normal
    - Insert
    - Command/Ex
    - Visual
+ Cómo entrar y salir (en serio)
+ Normal Mode
    + Movimientos básicos
    + Text Objects y la filosofía de Vim 
+ Insert Mode
    + Las reglas de Insert
    + CTRL 
+ Plugins y vimrc
+ Más información
+ Cheat Sheet

# Propósito
## Los propósitos de esta charla son
+ Que *intimen* con sus teclados 
+ Que evalúen las herramientas que utilizan en su día a día.
+ Si Vim fuese una espada, que pudieren cortar jamón con ella. 

Esto es **independiente** al editor (o cualquier otra herramienta)
que decidan utilizar.

# ¿Qué distingue a Vim? ¿Por qué Vim?
## Hay dos cosas que distinguen a Vim entre editores
- Es un editor **modal**
    - Las teclas se comportan de manera diferente según el modo en el que uno esté.
- Sus comandos son **compuestos**
    - Tiene comandos que son **generales** y **contextuales**.
    - Editores como Emacs, Sublime, Atom, etc. tienen comandos que invocan funciones específicas.

# Instalación
\Huge{www.vim.org}
\vspace{0.5cm}

\normalsize 

+ La versión del repositorio de Debian es la más actual. Recomiendo hacer \textbf{sudo apt install vim-gtk}.\footnote{después de 
\textbf{sudo apt update}.}

+ Si lo prefieren, pueden instalar gVim, la versión gráfica de Vim.

# Antes de empezar..
\large

Las diapositivas, su código, y algunos ejemplos que trabajaremos están en un repositorio de Github.

\vspace{1cm}

\textbf{git clone https://github.com/aricav96/learnvim.git}

# Los modos

Hay muchos modos en Vim, pero nos interesan los 4 más básicos.  Estos son: 
\vspace{0.5cm} 

## Normal
Es el modo default. Aquí es donde ocurre buena parte de la magia (*la edición*). 
Se accede a él presionando la tecla ESC.

## Insert
Es el modo en el que se escribe el texto. Hay muchas maneras de acceder a él:
"A/a", "I/i", "c{movement}", "S/s", "O/o"...

# Los modos
## Command/Ex
Es el modo para ejecutar comandos y activar o desactivar variables del editor. 
Se accede a él tecleando ":" en Normal Mode. En realidad, Command (o 
Command-line mode) es Ex Mode ejecutado una sola vez. A Ex mode se accede 
tecleando Q en Normal Mode.

## Visual
Es un modo en el que se navega como en Normal Mode, pero hay un indicador de
texto elegido. Se accede a él mediante "v", "V" o CTRL-V en Normal Mode.
\vspace{0.5cm}

De estos cuatro, le pondremos particular atención a **Normal** y a **Insert**.

# Cómo entrar y salir
## Para entrar..
Basta correr \textbf{vim <filename>} o \textbf{vim} (sin archivo).
En el segundo caso, se tiene que usar \textbf{:e <path>} para abrir el archivo deseado.

## Para salir..
+ En Normal Mode, hay que hacer \textbf{:q}
+ ... o \textbf{:wq} 
    - Esto guarda (write) y cierra (quit)
+ Sus equivalentes son (también en Normal Mode)
    - \textbf{ZQ}
    - \textbf{ZZ} 
    - \textbf{ZZ} no se queja si no se han hecho cambios...

#
\centering 
\Huge \textbf{NORMAL MODE}

\normalsize ¿Por qué creen que se llama Normal?

# Movimientos básicos
+ El movimiento en Vim se hace en Normal Mode.
+ El movimiento más básico se hace con las teclas \textbf{h, j, k y l}
    - h = izquierda
    - j = abajo 
    - k = arriba
    - l = derecha
+ Los movimientos pueden ser prefijados con un número
    - E.g. 2j mueve el cursor dos líneas hacia abajo.

# Text Objects y la filosofía de Vim 
Vim reconoce ciertos "objetos", como palabras, oraciones, párrafos, bloques 
de código delimitados (por paréntesis, llaves o corchetes) y tags. Estos también
tienen sus teclas asignadas en Normal Mode.

- w/W, b/B, e/E para palabras (¿qué constituye una palabra?).
- () para oraciones.
- {} para párrafos.
- % para delimitadores de bloques.

\vspace{0.2cm}

Asimismo, Vim se puede mover a partes del archivo por líneas

- 0/$ para el comienzo/final de la línea.
- ^/_ para el primer caracter de la línea.
- g_ para el último caracter de la línea.
- gg/G para ir a una línea específica (e.g. 2G te deja en la línea 2).

# Más movimientos 
Algunos movimientos útiles son

- CTRL-B CTRL-U CTRL-Y scroll up
- CTRL-F CTRL-D CTRL-E scroll down
- CTRL-O CTRL-I saltar frenéticamente por el jumplist 

Hay otros movimientos que son útiles cuando queremos preservar la posición del cursor

- zz posiciona la línea en el centro de la pantalla
- zt posiciona la línea hasta arriba
- zb posiciona la línea hasta abajo

# Búsquedas
En casos más heterodoxos, podemos emplear búsquedas con:

- f/F busca un caracter hacia adelante/hacia atrás
- "/" nos permite escribir un regex para buscar

# Marcas
En casos aún más heterodoxos, podemos emplear marcas

- m{a-zA-Z} crea una marca en el lugar donde está el cursor
- '{a-zA-Z} navega a dicha marca (principio de línea)
- \`{a-zA-Z} navega a dicha (exactamente a donde está la marca).

# Verbo + Objeto
Así como podemos prefijar movimientos, podemos prefijar comandos con movimientos.

- cw = change word
- c} = change paragraph
- dw = delete word
- d\) = delete sentence

Otros comandos ya incluyen una mezcla de movimiento e inserción

- s = substitute
- r = replace
- a = append
- A = append EOL
- S = substitute line ...

Me tomaré la libertad de poner un **gran recordatorio** aquí para parar y demostrar las demás
porque la verdad son bastantes jejejeje.

#
\centering 
\Huge \textbf{INSERT MODE}

# Las reglas de Insert  
En \textbf{Insert Mode} las teclas actúan como siempre. Es el modo donde se puede 
escribir como lo sabemos (y amamos) hacer. 

\vspace{0.5cm}

Esto tiene una implicación importante respecto a teclas modificadoras: Las combinaciones
de CTRL también son únicas dependiendo del modo en el que nos encontremos.

# CTRL
+ \textbf{CTRL-a} inserta texto recientemente añadido. Es el dot command de Insert Mode.
+ \textbf{CTRL-r} + \textbf{registro} nos permite poner texto en el \textbf{registro} referido.
+ \textbf{CTRL-n y CTRL-p} nos permiten autocompletar según lo que hay en el documento.
+ \textbf{CTRL-x} nos pone en un modo especial para autocompletar

Vim tiene definido en dónde va a buscar (set complete?). Para indicarle que busque en archivos de un
mismo proyecto, es preciso utilizar **ctags**.

# Plugins y vimrc
- Vanilla(???) Vim es bonito, pero hay algunos plugins que valen la pena.
- Tim Pope es nuestro pastor, nada nos faltará. 

\centering
\includegraphics[height=2in]{tpope.jpg}

# Plugins y vimrc
## Algunos de los plugins más célebres de Tpope son
- vim-surround
- vim-commentary
- vim-sensible

## ¿Dónde van?
Sin un administrador, hay que descargarlos, ponerlos en .vim/plugin.
Es importante que tengan permiso de ejecución.

# Más información
Hay muchas fuentes para consultar sobre Vim:

## Documentación
- vimtutor
- :help 
- man pages

## Libros
- "Practical Vim" de Drew Neil
- "The Vim Tutorial and Reference" Steve Oualline

#
\centering
\Huge 

**¿Dudas?**

\normalsize 
\vspace{2cm}

(si no, party tricks maybe?)

# Cheat Sheet
\includegraphics[height=2.8in]{cheat-sheet.jpg}


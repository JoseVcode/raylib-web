all:
	emcc -o index.html main.c -Os -Wall $(HOME)/raylib/src/libraylib.web.a -I$(HOME)/raylib/src -L$(HOME)/raylib/src -s USE_GLFW=3 -s ASYNCIFY --shell-file $(HOME)/raylib/src/minshell.html -DPLATFORM_WEB

server:
	python3 -m http.server 8000

run: all server

msg ?= Actualizacion
push:
	git add .
	git commit -m "$(msg)"
	git push
#make push msg="commit de prueba"
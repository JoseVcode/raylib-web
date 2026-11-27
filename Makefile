CC = emcc
CXX = em++

COMMON_FLAGS = -Os -Wall -Wextra -Iinclude -I$(HOME)/raylib/src -DPLATFORM_WEB
CFLAGS = -std=c99 $(COMMON_FLAGS)
CXXFLAGS = -std=c++20 $(COMMON_FLAGS)

LDFLAGS = $(HOME)/raylib/src/libraylib.web.a -L$(HOME)/raylib/src -s USE_GLFW=3 -s ASYNCIFY --shell-file $(HOME)/raylib/src/minshell.html #--preload-file assets

SRCS_C = $(wildcard src/*.c)
SRCS_CPP = $(wildcard src/*.cpp)
OUT_DIR = web

all:
	mkdir -p $(OUT_DIR)
	$(CC) -o $(OUT_DIR)/index.html $(SRCS_C) $(CFLAGS) $(LDFLAGS)

c++:
	mkdir -p $(OUT_DIR)
	$(CXX) -o $(OUT_DIR)/index.html $(SRCS_CPP) $(CXXFLAGS) $(LDFLAGS)

server:
	python3 -m http.server 8000 -d $(OUT_DIR)

run: all server

run-cpp: c++ server

clean:
	rm -rf $(OUT_DIR)

msg ?= Actualizacion
push:
	git add .
	git commit -m "$(msg)"
	git push
#make push msg="commit de prueba"

deploy: all
	git add -f web
	git commit -m "Deploy web"
	git subtree split --prefix web -b gh-pages
	git push -f origin gh-pages:gh-pages
	git branch -D gh-pages
	git reset HEAD~1
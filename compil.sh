export LD_LIBRARY_PATH=./libs/
g++ main.cpp  -I ./includes/ -L ./libs/ -lgdl_gl -lGL -lGLEW -ldl -lrt -lfbxsdk -lSDL2 -lpthread -ldl
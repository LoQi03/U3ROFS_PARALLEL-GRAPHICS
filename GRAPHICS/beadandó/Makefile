all:
	gcc -Iinclude/ src/texture.c src/game.c src/app.c src/camera.c src/main.c src/scene.c src/utils.c -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -w -lobj -lopengl32 -lm -o dino_run.exe -fopenmp -Wall -Wextra -Wpedantic

linux:
	gcc -Iinclude/ src/app.c src/camera.c src/main.c src/scene.c src/utils.c -lobj -lSDL2 -lSDL2_image -lGL -lm -o dino_run -Wall -Wextra -Wpedantic -Werror -Q3

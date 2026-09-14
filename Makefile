CC = gcc

TARGET = Colorist

SRC = src/main.c src/rmedia.c

CFLAGS = -Wall -Wextra -std=c11

RAYLIB_LIBS = -lraylib -lopengl32 -lgdi32 -lwinmm

FFMPEG_CFLAGS = $(shell pkg-config --cflags libavcodec libavformat libavutil libswscale libswresample)

FFMPEG_LIBS = $(shell pkg-config --libs libavcodec libavformat libavutil libswscale libswresample)


all: $(TARGET)


$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS) $(FFMPEG_CFLAGS) $(RAYLIB_LIBS) $(FFMPEG_LIBS)


rebuild: clean all


clean:
	rm -f $(TARGET)
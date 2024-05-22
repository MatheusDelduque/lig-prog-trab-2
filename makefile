CC = g++
CFLAGS = -Wall 

SRCS = main.cpp time.cpp liga.cpp
OBJ_DIR = compilados
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

TARGET = dados

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o ./executaveis/$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o ./executaveis/$(TARGET)
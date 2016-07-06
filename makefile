CC = g++
CFLAGS = -c -pthread -lpthread -std=c++0x -Wl,--no-as-needed -ldl
DIR_HARDWARE = ./hardware
DIR_MIDDLEWARE = ./middleware
INCLUDE_DIR = -I ./include -I $(DIR_MIDDLEWARE)/include -I $(DIR_HARDWARE)/include
SOURCES_DIR = ./src
SOURCES = $(wildcard $(SOURCES_DIR)/*.cpp)
OUTDIR = ./bin
OBJECTS = $(addprefix $(OUTDIR)/,$(notdir $(SOURCES:.cpp=.o)))
EXECUTABLE = Rewest

all: $(EXECUTABLE)

$(EXECUTABLE): $(OUTDIR)/main.o $(OUTDIR)/Arduino.o $(OUTDIR)/Serial.o $(OUTDIR)/Sensors.o $(OUTDIR)/Requests.o $(OUTDIR)/Database.o
	$(CC) $(OUTDIR)/main.o $(OUTDIR)/Arduino.o $(OUTDIR)/Serial.o $(OUTDIR)/Sensors.o $(OUTDIR)/Requests.o $(OUTDIR)/Database.o -o $@ -pthread -lpthread -std=c++0x -Wl,--no-as-needed -ldl

$(OUTDIR)/main.o: ./src/main.cpp
	$(CC) $(CFLAGS) $(INCLUDE_DIR) ./src/main.cpp -o $(OUTDIR)/main.o

$(OUTDIR)/Arduino.o: ./middleware/src/Arduino.cpp
	$(CC) $(CFLAGS) $(INCLUDE_DIR) ./middleware/src/Arduino.cpp -o $(OUTDIR)/Arduino.o

$(OUTDIR)/Serial.o: ./hardware/src/Serial.cpp
	$(CC) $(CFLAGS) $(INCLUDE_DIR) ./hardware/src/Serial.cpp -o $(OUTDIR)/Serial.o

$(OUTDIR)/Sensors.o: ./src/Sensors.cpp
	$(CC) $(CFLAGS) $(INCLUDE_DIR) ./src/Sensors.cpp -o $(OUTDIR)/Sensors.o

$(OUTDIR)/Requests.o: ./src/Requests.cpp
	$(CC) $(CFLAGS) $(INCLUDE_DIR) ./src/Requests.cpp -o $(OUTDIR)/Requests.o

$(OUTDIR)/Database.o: ./src/Database.cpp
	$(CC) $(CFLAGS) $(INCLUDE_DIR) ./src/Database.cpp -o $(OUTDIR)/Database.o
clean:
	rm -f $(OUTDIR)/*.o $@


#$(EXECUTABLE): $(OBJECTS)
#	   $(CC) $(INCLUDE_DIR) -o $@ $^

#$(OUTDIR)/%.o: $(SOURCES_DIR)/%.cpp
#	   $(CC) $(INCLUDE_DIR) $(CFLAGS) -o $@ $<

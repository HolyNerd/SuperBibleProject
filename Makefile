
MAKE = g++ -std=c++11
SOURCE = /home/holynerd/Desktop/Projects/SuperBibleProject/Source/
INCLUDE = /home/holynerd/Desktop/Projects/SuperBibleProject/includes/
HEADER = /home/holynerd/Desktop/Projects/SuperBibleProject/Headers/
LIB = /home/holynerd/LibsOpenGL/
LIB_LINK = -lsb7 -lglfw3 -ldl -lX11 -lXrandr -lXinerama -lXi -lXxf86vm -lXcursor -lGL -lpthread


#FINAL EXECUTABLE PROGRAM
$(SOURCE)Application: $(SOURCE)application.o $(SOURCE)compileShader.o \
	$(SOURCE)createShader.o $(SOURCE)readShader.o $(HEADER)functions.h \
	$(HEADER)myApplication.h 
	$(MAKE) -o Application $(SOURCE)application.o $(SOURCE)compileShader.o \
	$(SOURCE)createShader.o $(SOURCE)readShader.o \
	-I$(INCLUDE) -I$(HEADER) -L$(LIB) $(LIB_LINK) 

$(SOURCE)application.o: $(SOURCE)myApplication.cpp $(HEADER)functions.h
	$(MAKE) -c $(SOURCE)myApplication.cpp -o$(SOURCE)application.o \
	-I$(INCLUDE) -I$(HEADER)

$(SOURCE)compileShader.o: $(SOURCE)compileShader.cpp $(HEADER)functions.h
	$(MAKE) -c $(SOURCE)compileShader.cpp -o$(SOURCE)compileShader.o \
	-I$(INCLUDE) -I$(HEADER)

$(SOURCE)createShader.o: $(SOURCE)createShader.cpp $(HEADER)functions.h
	$(MAKE) -c $(SOURCE)createShader.cpp -o$(SOURCE)createShader.o \
	-I$(INCLUDE) -I$(HEADER)

$(SOURCE)readShader.o: $(SOURCE)readShader.cpp $(HEADER)functions.h
	$(MAKE) -c $(SOURCE)readShader.cpp -o$(SOURCE)readShader.o \
	-I$(INCLUDE) -I$(HEADER)


clean:
	rm -f $(SOURCE)*.o

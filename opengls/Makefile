CC = g++
CXXFLAGS = -g -std=c++11 -Wall  

INCLUDES = -I./Core -I./Core/Init -I./Dependencies/freeglut -I./Dependencies/glew -I./Dependencies/glm -I./Managers -I./Rendering -I./Rendering/Models 

LIBS = -lGL -lglut -lGLEW

# source files
SRCS = Core/Init/InitGLEW.cpp Core/Init/InitGLUT.cpp Managers/ShaderManager.cpp Managers/ModelsManager.cpp Managers/SceneManager.cpp Managers/SystemManager.cpp Rendering/Models/Model.cpp Rendering/Models/Camera.cpp Rendering/Models/Cube.cpp Rendering/Models/CustomModel.cpp Rendering/Systems/ParticleSystem.cpp Main.cpp  

OBJS = $(SRCS:.cpp=.o)

MAIN = simpleScene

.PHONY: depend clean

all:    $(MAIN)
	@echo successfully compiled

$(MAIN): $(OBJS) 
	$(CC) $(CXXFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

.c.o:
	$(CC) $(CXXFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) *.o */*.o */*/*.o *~ $(MAIN)

depend: $(SRCS)
	makedepend $(INCLUDES) $^


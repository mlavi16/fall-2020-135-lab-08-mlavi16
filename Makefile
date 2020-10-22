OBJECTS = editImages.o imageio.o

main: main.o ${OBJECTS}
	g++ -o main main.o ${OBJECTS}

main.o: main.cpp editImages.h imageio.h

editImages.o: editImages.cpp editImages.h imageio.h

imageio.o: imageio.cpp imageio.h


sample: sample.o imageio.o
	g++ -o sample sample.o imageio.o

sample.o: sample.cpp imageio.h


clean:
	rm -f sample.o ${OBJECTS}
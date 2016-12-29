hangman: src/main.cpp
	g++ -std=c++0x -o bin/hangman src/main.cpp src/model/Gallow.cpp src/model/WordDB.cpp src/controller/GallowController.cpp src/view/GallowView.cpp 

clean: 
	rm -rf bin/* 

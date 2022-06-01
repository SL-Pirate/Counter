mkdir ./bin
g++ -v -pipe ./*.cpp `wx-config --cxxflags --libs` -o ./bin/counter.bin

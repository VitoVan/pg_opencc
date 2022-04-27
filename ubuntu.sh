sudo apt install postgresql-13
sudo apt search postgresql-server-dev-13
sudo apt install make
sudo install gcc
sudo apt install libopencc-dev
sudo apt install pkg-config

cc -I/usr/include/postgresql/13/server/ -fPIC -c pg_opencc.c -o pg_opencc.o
cc -shared pg_opencc.o -o pg_opencc.so

sudo make install

# SQL

# CREATE EXTENSION pg_opencc;

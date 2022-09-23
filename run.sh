gcc -Wall main.c \
./dataprovider/repository/buscar-usuarios.repository.c \
./dataprovider/repository/criar-usuario.repository.c \
./core/usecase/login-usuario.usecase.c \
./client/socket-client.c -o start

./start
gcc -Wall main.c \
./repository/buscar-usuarios.repository.c \
./repository/criar-usuario.repository.c \
./usecase/login-usuario.usecase.c \
./service/buscar-usuarios.service.c \
./client/socket-client.c -o start

./start
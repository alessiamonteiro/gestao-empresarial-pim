gcc -Wall main.c \
./repository/buscar-usuarios.repository.c \
./repository/criar-usuario.repository.c \
./usecase/criar-usuario.usecase.c \
./service/buscar-usuarios.service.c \
./service/login-usuario.service.c \
./service/criar-usuario.service.c \
./client/socket-client.c -o start

./start
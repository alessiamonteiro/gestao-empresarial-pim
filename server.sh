gcc server.c \
./repository/buscar-usuarios.repository.c \
./repository/criar-usuario.repository.c \
./controller/buscar-usuarios.controller.c \
./controller/login-usuario.controller.c \
./controller/criar-usuario.controller.c \
./usecase/buscar-usuarios.usecase.c \
./usecase/criar-usuario.usecase.c \
./usecase/login-usuario.usecase.c \
-o server

./server
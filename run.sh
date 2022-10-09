gcc -Wall main.c \
./repository/buscar-usuarios.repository.c \
./repository/criar-usuario.repository.c \
./usecase/criar-usuario.usecase.c \
./service/buscar-usuarios.service.c \
./service/login-usuario.service.c \
./service/criar-usuario.service.c \
./pages/menu.page.c \
./pages/login.page.c \
./pages/cadastro.page.c \
./pages/perfil.page.c \
./pages/home.page.c \
./pages/buscar-usuarios.page.c \
./client/socket-client.c -o start

./start
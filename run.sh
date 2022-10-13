gcc -Wall main.c \
./repository/criar-funcionario.repository.c \
./repository/buscar-funcionarios.repository.c \
./repository/buscar-cargos.repository.c \
./service/buscar-usuarios.service.c \
./service/login-usuario.service.c \
./service/criar-usuario.service.c \
./pages/menu.page.c \
./pages/login.page.c \
./pages/cadastro.page.c \
./pages/perfil.page.c \
./pages/home.page.c \
./pages/buscar-usuarios.page.c \
./pages/buscar-funcionarios.page.c \
./utils/time.utils.c \
./client/socket-client.c -o start 

./start
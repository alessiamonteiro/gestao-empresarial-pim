gcc -Wall main.c \
./service/buscar-usuarios.service.c \
./service/buscar-funcionarios.service.c \
./service/login-usuario.service.c \
./service/criar-usuario.service.c \
./service/criar-funcionario.service.c \
./pages/menu.page.c \
./pages/login.page.c \
./pages/cadastro.page.c \
./pages/cadastro-funcionario.page.c \
./pages/perfil.page.c \
./pages/home.page.c \
./pages/buscar-usuarios.page.c \
./pages/buscar-funcionarios.page.c \
./utils/time.utils.c \
./repository/criar-relatorio-funcionarios.repository.c \
./repository/buscar-funcionarios.repository.c \
./repository/buscar-cargos.repository.c \
./usecase/criar-relatorio-funcionarios.usecase.c \
./client/socket-client.c -o start 

./start